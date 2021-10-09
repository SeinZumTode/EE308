// pages/index_multi-player/index_multi-player.js
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
      total: 0,
      result : [0, 0, 0],
      rank: 0
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

        
        this.setData({
          rank: this.data.rank + 1
        });
      } else{
        clearInterval(this.global.timer);
        var arr = [this.data.num1+1,this.data.num2+1,this.data.num3+1,this.data.num4+1,this.data.num5+1,this.data.num6+1];

          //冒泡排序
          for (var i = 0; i < arr.length - 1; i++) {
            for (var j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    var temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } 
          }
        var str = arr[0]+""+arr[1]+""+arr[2]+""+arr[3]+""+arr[4]+""+arr[5];
       
        
        var re = ["114444","444444","111111","222222|333333|555555|666666","444446","344444","244444","144444","111116|222226|333336|555556","111115|222225|333335|566666","111114|222224|333334|455555|466666","111113|222223|355555|366666","111112|233333|255555|266666","122222|133333|155555|166666","444466","444456","444455","344446","244446|344445","144446|244445|344444","144445|244444|334444","234444","13[4]{4}|22[4]{4}","124444","123456","[^4]*[4]{3}[^4]*","44[5]{4}|44[6]{4}|[1]{4}44|[2]{4}44|[3]{4}44","[1]{4}.*4.*|.*[2]{4}.*4.*|.*[3]{4}.*4.*|.*4.*[5]{4}.*|.*4.*[6]{4}","[^4]*[1]{4}[^4]*|[^4]*[2]{4}[^4]*|[^4]*[3]{4}[^4]*|[^4]*[5]{4}[^4]*|[^4]*[6]{4}[^4]*","[^4]*[4]{2}[^4]*","[^4]*[4]{1}[^4]*"];


        var show = ["状元插金花","六博红","六杯红","六博黑","五红带六","五红带三","五红带二","五红带一","五子带六","五子带五","五子带四","五子带三","五子带二","五子带一","四红带十二","四红带十一","四红带十","四红带九","四红带八","四红带七","四红带六","四红带五","四红带四","四红带三","对堂","三红","四进带二举","四进带一秀","四进","二举","一秀","什么都没有"];

        var num = -1;

        for(var i = 0; i < re.length ; i++){
          if(str.match(re[i]) != null){
             num = i;
             break;
          }
        }

        if(num == -1){
          num = show.length - 1;
        }
        var temp_str='result['+(this.data.rank-1)+']';
        this.setData({
          [temp_str] : num,
        });
        if (this.data.rank == 3){
          function finMinIndex(arr,start){   
            var oMin=arr[start]; 
            var oMinIndex=start; 
            
            for(var i=0;i<arr.length; i++){   
              if(arr[i]<oMin){   
                console.log(oMin);
                oMin=arr[i] 
                oMinIndex=i; 
              } 
            } 
            return oMinIndex 
          }
          console.log(this.data.result);
          console.log('最小值是：'+this.data.result[finMinIndex(this.data.result,0)]+',所在的位置是第'+finMinIndex(this.data.result,0)+'个');
  
          var result_Rank = finMinIndex(this.data.result,0) + 1;
          wx.showModal({
            title: '多人模式结果',
            content: this.data.rank+'号玩家的结果是: '+show[num] 
            +'\n本次游戏胜利者是：'+result_Rank+'号玩家',
          })
          this.setData({
            rank: 0
          });
        }else{
          wx.showModal({
            title: '结果',
            content: this.data.rank+'号玩家的结果是:\r\n'+show[num],
            success: function (res) {
              if (res.confirm) {
                console.log('用户点击确定')
              } else {
                console.log('用户点击取消')
              }
            }
          })
        }
      }
      this.setData({
        dice: this.data.dice, 
        buttonType : (this.global.isRand) ? 'default' : 'primary',
        isShow: (this.global.isRand) ? 'show':'hidden',
      });
  
    },
  })
  