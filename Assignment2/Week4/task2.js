//Works with v-show,v-if,v-else-if,and v-else
var num = new Vue({
    el: '#num',
    data: {
      type: 'SIT102',
      ok: true
    }
})

//A list created using v-for that accepts new values
var app =new Vue({
    el:'#app',
    data:{
        list:'My Grocery List',
        newItem:'',
        Items:[
            'bananas',
            'chicken',
            'milk'
        ]
    },
    methods:{
        saveItem:function(){
            this.Items.push(this.newItem);
            this.newItem='';
        }
    }
})




