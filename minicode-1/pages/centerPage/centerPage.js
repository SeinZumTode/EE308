Page({
    global : {
        timer : null ,
        isRand : false
    },
    data: {
      dice : ['first','second','third','fourth','fifth','sixth'],
      buttonType : 'primary',
      buttonValue : '博一下',
      isShow:'hidden',
      num1 : 3,
      num2 : 3,
      num3 : 3,
      num4 : 3,
      num5 : 3,
      num6 : 3,
      total: 0
    },
    shakeClick: function () { 
      let me = this;
      this.global.isRand = !this.global.isRand;
      if ( this.global.isRand ) {
        this.global.timer = setInterval(function (){
          let num1 = Math.floor(Math.random()*6);
          let num2 = Math.floor(Math.random()*6);
          let num3 = Math.floor(Math.random()*6);
          let num4 = Math.floor(Math.random()*6);
          let num5 = Math.floor(Math.random()*6);
          let num6 = Math.floor(Math.random()*6);
          me.setData({num1 : num1});
          me.setData({num2 : num2});
          me.setData({num3 : num3});
          me.setData({num4 : num4});
          me.setData({num5 : num5});
          me.setData({num6 : num6});
          me.setData({total : num1+num2+num3+num4+num5+num6+6});
        },50);
       } else {
        clearInterval(this.global.timer);
      }


      this.setData({
        dice: this.data.dice, 
        buttonType : (this.global.isRand) ? 'default' : 'primary',
        isShow: (this.global.isRand) ? 'hidden':'show',
      });
  
    },
  })
  