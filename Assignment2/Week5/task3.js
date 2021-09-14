var app = new Vue({
    el: '#app',
    data: {
      message: 'I love pizza!'
    },
    methods: {
      reverseMessage: function () {
        this.message = this.message.split('').reverse().join('')
      }
    }
})

var app2 = new Vue({
    el: '#app-2',
    data: {
      text: '',
      age: '',
      university:''
    }
})