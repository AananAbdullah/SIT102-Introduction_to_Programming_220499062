//Vue instance to create a dynamic drop down array
var app =new Vue({
    el: '#app',
    data: {
      selected: '',
      options: [
        { text: 'One', value: 'SIT102 Introduction to Programming'},
        { text: 'Two', value: 'SIT103 Data and Information Management' },
        { text: 'Three', value: 'SIT182 Real World Practices for Cybersecurity'}
      ]
    }
  })