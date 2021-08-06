//Function to display alert message on newsletter form page
function Reminder() {  
    alert("Please make sure you have filled out all fields properly.");
}
    // Get the modal
   var modal = document.getElementById('id01');
                        
   // When the user clicks anywhere outside of the modal, close it
   window.onclick = function(event) {
       if (event.target == modal) {
           modal.style.display = "none";
       }
   }