<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<style>
table,td,th {
	margin:auto;
	width:450px;
	height:50px;
	text-align:center;
	table-layout: fixed;
}
td,th {
	 	border: 1px solid #F2F2F2;
	 	font-style: italic;
	    font-family:"Times New Roman";
	    font-size: 50px;
}
th {
	background-color:#00BFFF;
}

#none {
	border-style:none;
	size:15; 
}
</style>
</head>
<body>
<form method=post action=calc_result.jsp>
	<table>
	<tr>
		<th colspan="2">CalCuLaTor</th>
	</tr>
	<tr>
		<td rowspan="7"><img src="image/cal.jpg"></td>
		<td id=none></td>
	</tr>
	<tr>
		<td id=none><input type="text" name="op1" value=0 style="text-align:center">
	</tr>
	<tr>
		<td id=none> <select name="operator"><option>+</option><option>-</option><option>*</option><option>/</option></select>
	</tr>
	<tr>
		<td id=none><input type="text" name="op2" value=0 style="text-align:center"></td>
	</tr>
	<tr>	
		<td id=none><input type="submit" value="="></td>	
	</tr>
	<tr>
		<td id=none><input type="text" disabled></td>
	</tr>
	<tr>
		<td id=none></td>
	</tr>

	<tr>
		<th colspan="2"></th>
	</tr>
	</table>
</form>
</body>
</html>