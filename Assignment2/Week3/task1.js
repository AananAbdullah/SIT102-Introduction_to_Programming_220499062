//Function to write output to screen wherever the div tag has the id strings
function display(strings){
    document.getElementById('strings').innerHTML += strings +'<br>';
}

//Function to replace a word of the sentence with another word
function replace(){
    let sentence=document.getElementById('change').innerHTML;
    document.getElementById('change').innerHTML=sentence.replace("Bangladesh","Australia");
}

//Displays the length of the string
var text="My name is Aanan";
display("The length of this sentence is " + text.length + ".");

//Slices the string at certain index
var message="I am looking forward to summer";
display("The sliced string is " + message.slice(24,30) + ".");

//Converts entire string to Uppercase
var str="Aanan Abdullah";
display(str +" is converted to Uppercase: " + str.toUpperCase());

//Converts entire string to lowercase
var str1="Hello";
display(str1+" is converted to lowercase: " + str1.toLowerCase());

//Trims whitespaces
var str2="  Removing Whitespace  ";
display("The trim method removes whitespaces from the string ends: " + str2.trim());

//Adds string to the beginning of another string
var str3="enjoying";
display(str3.padStart(13,"I am "));

//Adds string to the ending of another string
var str4="I am enjoying ";
display(str4.padEnd(20,"SIT120 "));

//Extracts specific characters by index 
var str5="Deakin University";
display("The charAt() method extracted " + str5.charAt(5) + " from " + str5);



