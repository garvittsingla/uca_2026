
function* calc(initial){
    let initalValue = initial;

    while(true){
        let input = yield initalValue;
        let value = input.value
        if(input.operation){
            if(input.operation == "add"){
                initalValue += value
               
            }else if(input.operation == "subtract"){
                initalValue -= value
                
            }else if(input.operation == "multiply"){
                initalValue*= value
               
            }else{
                initalValue/= value
               
            }
        }
    }

}

const calculator = calc(50);

console.log(calculator.next().value);// 50

console.log(calculator.next({ operation: "add", value: 30 }).value); //80

console.log(calculator.next({ operation: "multiply", value: 2 }).value); //160

console.log(calculator.next({ operation: "subtract", value: 5 }).value); //155

console.log(calculator.next({ operation: "divide", value: 5 }).value); //31

