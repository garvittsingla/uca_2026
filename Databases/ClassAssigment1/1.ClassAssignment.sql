-- Q1. List the name of every student along with their department name,
-- the courses they are enrolled in, and the grade obtained - for Fall2023 only.
-- Sort by department, then student name.
SELECT
    s.name ,
    d.dept_name ,
    c.course_name,
    e.grade 
FROM Student s 
JOIN Department d ON s.dept_id = d.dept_id 
JOIN Enrollment E on s.student_id = e.student_id 
JOIN Course c on  e.course_id = c.course_id 
WHERE e.semester = 'Fall2023' 
ORDER BY d.dept_name,s.name;

-- OR

SELECT s.name,d.dept_name,c.course_name,e.grade 
    FROM STUDENT s,Department d,Course c,Enrollment e 
    WHERE s.dept_id = d.dept_id 
    AND s.student_id = e.student_id 
    AND e.course_id = c.course_id 
    AND e.semester = 'Fall2023';

-- Q2. Find the names of all instructors, their department, and the total number of distinct 
-- students who have ever taken any course they teach. Instructors with zero 
-- students should still appear, with a count of 0

SELECT 
    i.name , 
    d.dept_name, 
    COUNT(e.student_id) AS count
FROM Instructor i 
JOIN Department d ON i.dept_id = d.dept_id 
LEFT JOIN course c ON i.instructor_id = c.instructor_id
LEFT JOIN Enrollment e ON c.course_id = e.course_id 
GROUP BY i.instructor_id, i.name, d.dept_name ;

-- Q3. List every course along with its instructor's name, the room and day 
-- it is scheduled, and the total number of students enrolled in it (any semester).

SELECT 
    c.course_name , 
    i.name , 
    cs.room_no AS room , 
    cs.day_of_week AS day , 
    COUNT(e.student_id) AS Studentcount 
FROM Course c 
JOIN Instructor i ON c.instructor_id = i.instructor_id 
JOIN Course_Schedule cs ON cs.course_id = c.course_id 
JOIN Enrollment e ON e.course_id = c.course_id 
GROUP BY c.course_id, c.course_name, i.name, cs.room_no, cs.day_of_week;

-- Or by subqueries

SELECT
    c.course_name, i.name,
    s.room_no,s.day_of_week,
    e.enrollment_count
FROM
    Course c, Instructor i,Course_Schedule s,
    (
        SELECT
            ee.course_id,COUNT(ss.student_id) as enrollment_count
        FROM
            Enrollment ee, Student ss
        WHERE
            ss.student_id=ee.student_id
        GROUP BY ee.course_id
    ) e
WHERE
    c.instructor_id=i.instructor_id AND s.course_id = c.course_id;


-- Q4. List the names of students who are enrolled in at least one course offered by a 
-- different department than their own home department.
--  Show student name, home department, course name, and the course's department.

SELECT 
    s.name AS name , 
    d1.dept_name AS home , 
    c.course_name,d2.dept_name AS course_department 
FROM Student s 
JOIN Department d1 ON s.dept_id = d1.dept_id 
JOIN Enrollment e ON s.student_id = e.student_id 
JOIN Course c ON e.course_id = c.course_id 
JOIN Department d2 ON c.dept_id = d2.dept_id 
WHERE s.dept_id <> c.dept_id;

-- Q5. Find pairs of students who are enrolled in the same course in the same semester but received different grades. 
-- Show both student names, the course name, the semester, and both grades. 
-- Avoid showing the same pair twice (e.g., don't show both "A-B" and "B-A").

SELECT
    s1.name AS student1 ,
    s2.name AS student2, 
    c.course_name, 
    e1.semester , 
    e1.grade AS grade1, 
    e2.grade AS grade2 
FROM Enrollment e1 
JOIN Enrollment e2 ON e1.course_id = e2.course_id 
AND e1.semester = e2.semester 
AND e1.grade <> e2.grade 
AND e1.student_id < e2.student_id  
JOIN Student s1 ON e1.student_id = s1.student_id 
JOIN Student s2 ON e2.student_id = s2.student_id 
JOIN Course c ON e1.course_id = c.course_id;


-- Q6. List the titles of books whose author has written books catalogued under more than one department.
-- (Hint: this needs Book joined to itself, or a 
-- GROUP BY author HAVING COUNT(DISTINCT dept_id) > 1, then joined back to fetch qualifying titles.)

SELECT 
    title
FROM 
    Book
WHERE 
    author IN (
        SELECT author
        FROM Book
        GROUP BY author
        HAVING COUNT(DISTINCT dept_id) > 1
    ); 

-- Q7. Find the names of instructors who teach more courses than the average number of courses taught per instructor 
-- (computed across all instructors who teach at least one course).
-- avg from course instructor_id
 SELECT instructor_id,COUNT(*) FROM Course group  by instructor_id; -- avg bhi chahiye and voh instructor id bhi chahiye

-- Q8. For each course, compute the "average grade point" of students enrolled in it, using this mapping: A = 4, B = 3, C = 2. 
-- Then list only the courses whose average grade point is higher than the overall average grade point across all enrollments in the university.
-- todo: will do it later


-- Q10. Find students who have issued a book but never made a Spring2024 fee payment.
--  Show student name, department, and how many books they've issued.
-- Not exists used because it is asked not even any user should have a payment in spring 2024
-- but when we use join , if same student will have payment in some other semester as well then it will take the name of that student 
SELECT s.name,d.dept_name,COUNT(bi.student_id) AS COUNT FROM Student s 
    JOIN Book_Issue bi ON bi.student_id = s.student_id 
    JOIN Department d ON d.dept_id = s.dept_id  
    WHERE NOT EXISTS(
        SELECT 1 FROM 
        Fee_Payment fp WHERE
        fp.student_id = s.student_id AND fp.semester = 'Spring2024';
    ) 
    GROUP BY bi.student_id;


-- Q11. (Relational division) Find the student(s) who have enrolled in every single 
-- course offered by their own home department.
-- (Hint: for each student, there should be no course in 
-- their department that they have not taken – this is a classic double-NOT EXISTS pattern.)

 SELECT * FROM Student s WHERE
    NOT EXISTS 
        (SELECT 1 FROM Course c 
        WHERE c.dept_id = s.dept_id 
        AND NOT EXISTS 
            (SELECT 1 FROM Enrollment e 
            WHERE e.student_id = s.student_id 
            AND e.course_id = c.course_id
            )
        );

-- Q12. Find instructor(s) for whom every student who has ever taken one of their 
-- courses received a grade of A or B only – i.e., no student of theirs has ever gotten a C or lower.
-- Show instructor name and department.