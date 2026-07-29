-- Create Database
CREATE DATABASE UniversityDB;

-- Use Database
USE UniversityDB;

-- Create Department Table
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50) NOT NULL
);

-- Create Instructor Table
CREATE TABLE Instructor (
    InstructorID INT PRIMARY KEY,
    InstructorName VARCHAR(100) NOT NULL,
    DeptID INT,
    Salary DECIMAL(10,2),
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

-- Create Student Table
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(100) NOT NULL,
    DeptID INT,
    DOB DATE,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

-- Create Course Table
CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    DeptID INT,
    InstructorID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID),
    FOREIGN KEY (InstructorID) REFERENCES Instructor(InstructorID)
);

-- Create Enrollment Table
CREATE TABLE Enrollment (
    StudentID INT,
    CourseID INT,
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);

-- Insert into Department
INSERT INTO Department (DeptID, DeptName)
VALUES
(1, 'CS'),
(2, 'Electronics'),
(3, 'Mechanical');

-- Insert into Instructor
INSERT INTO Instructor (InstructorID, InstructorName, DeptID, Salary)
VALUES
(101, 'Dr. Rao', 1, 95000),
(102, 'Dr. Mehta', 2, 88000),
(103, 'Dr. Iyer', 1, 72000),
(104, 'Dr. Sen', 3, 60000);

-- Insert into Student
INSERT INTO Student (StudentID, StudentName, DeptID, DOB)
VALUES
(1, 'Aarav', 1, '2003-05-14'),
(2, 'Diya', 1, '2003-08-22'),
(3, 'Kabir', 2, '2003-01-30'),
(4, 'Meera', 3, '2003-03-11'),
(5, 'Rohan', 1, '2003-07-19');

-- Insert into Course
INSERT INTO Course (CourseID, CourseName, DeptID, InstructorID)
VALUES
(201, 'DBMS', 1, 101),
(202, 'OS', 1, 103),
(203, 'Circuits', 2, 102),
(204, 'Thermo', 3, 104);

-- Insert into Enrollment
INSERT INTO Enrollment (StudentID, CourseID, Grade)
VALUES
(1, 201, 'A'),
(1, 202, 'B'),
(2, 201, 'A'),
(3, 203, 'B'),
(5, 201, 'C');