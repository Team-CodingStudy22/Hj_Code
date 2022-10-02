<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice11</title>
	<style>
		h1 {
			text-align:center;
		}
		table, td{
		    border: 1px solid #444444;
		    margin:1px;
		    padding:10px;
		    width:600px;
		 }
	</style>
</head>
<body>
	<table>
	<% 
	out.println("<h1>구구단 출력");
	out.println("<hr>");

	for(int i=1;i<=8;i++){
		if(i==1 || i==5)
			out.println("<tr>");
       	out.println("<td>");
       	for(int j=1; j<=9; j++) 
	       	out.println((i+1) + "*" + j + "=" + (i+1)*j + "<br>");
       	out.println("</td>");
    }
	%>
	</table>
</body>
</html>