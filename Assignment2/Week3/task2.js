//Functions to write output to screen wherever the div tag has the id strings
function display(number){
    document.getElementById('number').innerHTML += number +'<br>';
}
function write(array){
    document.getElementById('array').innerHTML+=array+'<br>';
}

//Converts number sums to string
display("The sum of 1000 and 500 is "+ (1000+500).toString() + ".");

//Displays a number in exponential notation
display("The exponential notation of 4.5 is "+ (4.5).toExponential());

//Displays a string with a specified number of decimal places
display("$42.525 should only have 2 decimal places like $" + (42.525).toFixed(2));

//Displays the number of milliseconds from a particular date
var date=new Date("2017-02-14");
display("The number of milliseconds passed between 14th February and today is "+ Number(date));

//Changes an array to a string
const units=["SIT120","SIT102","SIT103","MIS201"];
write("These are my 2nd trimester units:" + units.toString());

//Joins an array using specified operator
write("Units Joined by plus sign: " + units.join("+"));

//Adding an element to the array
units.push("STP010");
write("STP010 was added to the array: " + units);

//Removing an element from the array
units.pop();
write("Units array with deleted element: " + units);

//Merging Arrays
const days=["Mon","Wed","Thurs","Fri"];
write("Joined array of units and their class days: " + units.concat(days));

//Slicing out and creating a new array from an existing array
write("The first 2 elements of the days array has been sliced out:" + days.slice(2));





