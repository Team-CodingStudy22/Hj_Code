<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Calendar</title>
	<style>
		table, td, tr, th {
  		border-collapse : collapse;
  		padding: 10px;
		}
	 	 #sun {color:red;}
		 #sat {color:blue;}
	</style>
</head>
<body>
<div>
	<table border="1">
		<%
			out.println("<tr>");
			out.println("<th id=sun>" + "일");
			out.println("<td>" + "월");
			out.println("<td>" + "화");
			out.println("<td>" + "수");
			out.println("<td>" + "목");
			out.println("<td>" + "금");
			out.println("<th id=sat>" + "토");
			
			for(int i=0;i<4;i++){
				out.println("<tr>");
				for(int j=0;j<7;j++) {
			   	 out.println("<td>");
			   	 out.println("&nbsp;");
				}
			}
		%>
	</table>
</div>
</body>
</html>