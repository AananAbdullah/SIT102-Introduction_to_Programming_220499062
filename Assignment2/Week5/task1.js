//Reusable List Component
Vue.component('list-item',{
    props:['list'],
    template:'<li>{{list.text}}</li>'
})

//Root Vue instance with an array
var app = new Vue({
    el:'#app',
    data:{
        groceryList:[
            {text:'Banana'},
            {text:'Milk'},
            {text:'Cheese'},
            {text:'Butter'},
            {text:'Chicken'}
        ]
    }
})