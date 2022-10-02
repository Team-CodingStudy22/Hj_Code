<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice10</title>
	<style>
		table, td, th{
		    border: 1px solid #444444;
		    margin:auto;
		    text-align:center;
		    width:600px;
		    height:30px;
		    font-weight: bold;
		 }
		 #sun {color:red;}
		 #sat {color:blue;}
	</style>
</head>
<body>
	<table>
	<% 
	
	out.println("<tr>");
	out.println("<td id=sun>" + "일");
	out.println("<td>" + "월");
	out.println("<td>" + "화");
	out.println("<td>" + "수");
	out.println("<td>" + "목");
	out.println("<td>" + "금");
	out.println("<td id=sat>" + "토");
	
	for(int i=0;i<4;i++){
		out.println("<tr>");
		for(int j=0;j<7;j++) {
       	 out.println("<td>");
       	 out.println("&nbsp");
		}
    }
	
	%>
	</table>
</body>
</html>