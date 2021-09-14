//Reusable List Component
Vue.component('list-item',{
    props:['list'],
    template:'<li>{{list.text}}</li>'
})

//Root Vue instance with an array
var app = new Vue({
    el:'#app',
    data:{
        activityList:[
            {text:'Activity 1'},
            {text:'Activity 2'},
            {text:'Activity 3'},
            {text:'Activity 4'},
            {text:'Activity 5'}
        ],
        count:0
    }
    
})