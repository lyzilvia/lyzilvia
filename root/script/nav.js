window.onload=function() {
	var aLi = document.getElementById('nav').children;
	var aA = [], aUl = [];
	var i = 0;
	var oTimer = null;
	
	for(i=0; i<aLi.length; i++) {
		aA.push(aLi[i].children[0]);
		if(aLi[i].children[1]) {
			aUl.push(aLi[i].children[1]);
		} else {
			aUl.push(0);
		}
	}
	
	for(i=0; i<aA.length; i++) {
		aA[i].myindex = aUl[i].myindex = i;
		
		aA[i].onmouseover = function() {
			if(oTimer) {
				clearTimeout(oTimer);
				oTimer = null;
			}
			
			for(i=0; i<aA.length; i++) {
				aA[i].className = '';
				if(aUl[i]) {aUl[i].style.display = 'none';}
			}
			
			this.className = 'on';
			if(aUl[this.myindex]) {aUl[this.myindex].style.display = 'block';}	
		};
		
		aUl[i].onmouseover = function() {
			if(oTimer) {
				clearTimeout(oTimer);
				oTimer = null;
			}
		};
		
		aA[i].onmouseout = aUl[i].onmouseout = function() {
			var index = this.myindex;
			oTimer = setTimeout(function() {
				//aA[index].className = ''; //鼠标移出后，最后经过的一级链接取消高亮
				if(aUl[index]) {aUl[index].style.display = 'none';}
				oTimer = null;
			}, 300);
		};
	}
};
