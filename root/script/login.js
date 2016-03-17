function checkvalid()
{
if (((document.getElementById('field1').value == "abcde") and (document.getElementById('field2').value == "12345678"))
	or ((document.getElementById('field1').value == "computer") and (document.getElementById('field2').value == "asdfg123"))
	or ((document.getElementById('field1').value == "comp123") and (document.getElementById('field2').value == "0123_xp"))){
window.alert("Welcome,"+ document.getElementById('field1').value + "!!")
}

function cancellog()
{
var r=confirm("Do you really want to cancel login?");
if (r==true)
  {
  window.location.href ='../eng/home.html'
  }
return false;
}
