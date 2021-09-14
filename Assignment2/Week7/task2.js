//Passing data to component using props
Vue.component('new-article',{
    props:['content'],
    template:'<article>{{content}}</article>'
})

var app = new Vue({
    el:'#app',
    data:{
        datacontent:'In Vue, props (or properties) are the way that data is passed from a parent component down to its child components.When we build our applications out of components, we end up building a data structure called a tree.'
    }
})