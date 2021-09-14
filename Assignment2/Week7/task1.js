//Global component registration
Vue.component('global',{
    template:'<h1>Global Component Test</h1>'
})

var globalComponent= new Vue({
    el:'#globalComponent',
    data:{
        message:'Global Components remain in the app build up even when they are not called.'
    }
});

//Local component registration
var localComponent= new Vue({
    el:'#localComponent',
    components:{
        'local':{
            template:'<h1>Local Component Test</h1>'
        },
    },
})