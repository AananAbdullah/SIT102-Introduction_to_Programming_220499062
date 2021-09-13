//Functions to write output to screen wherever the div tag has the id strings
function display(get){
    document.getElementById('get').innerHTML += get +'<br>';
}

//Displays the number of milliseconds from a specific date
const d= new Date("2018-09-12");
display("The number of elapsed milliseconds from 12th September 2018 till today: "+ d.getTime());

//Displays the year as a 4 digit number
display("The year in the date 2018-09-12: " + d.getFullYear());

//Displays the month as a number
display("September: " + (d.getMonth()+1));

//Retrieves the day number from a date and displays it as a day name
const days=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];
display("The day on 12th September 2018 was " + days[d.getDay()]);

//Function to change the entire date
function changedate(){
d.setFullYear(2021,7,4);
document.getElementById('set').innerHTML= d;
}

//Function to change date by adding days
function adddays(){
    d.setDate(d.getDate()+30);
    document.getElementById('day').innerHTML=d;
}

//Comparison Using Dates
var text;
const today = new Date();
const someday = new Date();
someday.setFullYear(2021, 1, 14);

if (someday > today) {
  text = "Today is before February 14, 2021.";
} else {
  text = "Today is after February 14, 2021.";
}
document.getElementById('compare').innerHTML=text;