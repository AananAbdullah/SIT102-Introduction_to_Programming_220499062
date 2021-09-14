//All of them declaratively render a few sentences
var app = new Vue({
    el: '#app',
    data:{
        intro: 'My name is Aanan Abdullah. I am currently pursuing the Bachelor of Information Techonology.'
    }
})

var app2 = new Vue({
    el: '#app-2',
    data:{
        facts: 'Random Facts About Me'
    }
})

var app3= new Vue({
    el:'#app-3',
    data:{
        books:'My favorite books are Fangirl,The Harry Potter Series,The Book Thief,and A Thousand Splendid Suns.'
    }
})

var app4= new Vue({
    el:'#app-4',
    data:{
        message:'I am practicing Vue for SIT120 Intro to Responsive Web Apps.'
    }
})