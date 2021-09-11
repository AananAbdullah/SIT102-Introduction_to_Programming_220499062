var app = new Vue({
    el:"#app",
    data(){
        return{
            title:"Todos",
            todoLists:[
                {id:'0',text:"Learn Vue",checked:false},
                {id:'1',text:"Start thinking about Assignment 1,",checked:false},
                {id:'2',text:"Complete weekly tasks",checked:false},
                {id:'3',text:"Go to bed by 12am",checked:false}
            ]
        };
    },
methods:{
    toggleItem(todoItem){
        todoItem.checked=!todoItem.checked
    }
}
});

