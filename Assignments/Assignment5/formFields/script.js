const fields = [
    "First Name",
    "Last Name",
    "Email"
  ];

const main = document.getElementById('main');

function generateForm(){
    const rows = fields.map((field)=>{
        return `
            <label>${field}</label> 
            <input type="text"> 
        `
    }).join('');
    main.innerHTML = rows;
}
generateForm();