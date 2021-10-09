Page({
    enterPoster_single:function(event){
        wx.redirectTo({url:"../index/index"});
    },
    enterPoster_multi:function(event){
        wx.redirectTo({url:"../index_multi-player/index_multi-player"});
    }
})