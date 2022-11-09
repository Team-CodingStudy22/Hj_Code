<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<%!

	int num1 = 0;
	int num2 = 0;
	int result = 0;
	String op = "+";
	
	public int calc(){
		if(op.equals("+"))
 			result = num1 + num2;
 		else if(op.equals("-"))
 			result = num1 - num2;
 		else if(op.equals("*"))
 			result = num1 * num2;
 		else if(op.equals("/"))
 			result = num1 / num2;
 		
 		return result;
	}
%>

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
<%
	num1 = Integer.parseInt(request.getParameter("n1"));
	num2 = Integer.parseInt(request.getParameter("n2"));
	op = request.getParameter("op");
%>
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
		<td id=none><input type="text" readonly <%out.println("value=\"" + num1 + "\""); %> style="text-align:center">
	</tr>
	<tr>
		<td id=none><input type="text" id=none <%out.println("value=\"" + op + "\""); %> style="text-align:center">
	</tr>
	<tr>
		<td id=none><input type="text" readonly <%out.println("value=\"" + num2 + "\""); %> style="text-align:center">
	</tr>
	<tr>	
		<td id=none><input type="text" id=none value = "=" style="text-align:center">	
	</tr>
	<tr>
		<td id=none><input type="text" readonly <%out.println("value=\"" + calc() + "\""); %> style="text-align:center">
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