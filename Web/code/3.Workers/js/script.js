// 1. Wague way, makes the UI unresponsive
// document.getElementById('btn').addEventListener('click',()=>{
//     console.log("btn clicked"); 
//     if (document.body.style.backgroundColor == "red") {
//         document.body.style.backgroundColor = "white";
//     } else {
//         document.body.style.backgroundColor = "red";
//     }
// })
// function heavyprocess(){
//     for(let i = 0 ; i < 10000000000 ; i ++){

//     }
//     console.log("task finished");
// }

// heavyprocess()

// // 2. Using async nature(it still blocks , main loop is executing , it still makes it difficult)
// document.getElementById('btn').addEventListener('click',()=>{
//         console.log("btn clicked"); 
//         if (document.body.style.backgroundColor == "red") {
//             document.body.style.backgroundColor = "white";
//         } else {
//             document.body.style.backgroundColor = "red";
//         }
//     })

// function heavyprocess(){
//     return new Promise((res,rej)=>{
//         for(let i = 0 ; i < 10000000000 ; i ++){

//         }
//         res("done");
//     })
// }


// console.log("task started")
// heavyprocess().then((msg)=>{
//     console.log(msg)
// })

// console.log("after")

// 3. using workers , UI not blocked 

const myworker = new Worker("./js/worker.js");

document.getElementById('btn').addEventListener('click',()=>{
            console.log("btn clicked"); 
            if (document.body.style.backgroundColor == "red") {
                document.body.style.backgroundColor = "white";
            } else {
                document.body.style.backgroundColor = "red";
            }
        })
        myworker.onmessage = (e) => {
            console.log(e.data); // "done"
        };
        
        myworker.postMessage(20000000000);``