users = [
    { name: "Alice", age:53 },
    { name: "Tim", age:74 }
];

const tab = document.getElementById("table");
function generateTable(){   
   const row = users.map((user)=>{
    return `<tr>
    <td>${user.name} </td>
    <td>${user.age}</td>
    </tr>
    `
   }).join('');

   tab.innerHTML = row;
}
generateTable()