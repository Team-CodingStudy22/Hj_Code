<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>greeting message</title>
</head>
<body>
	<div class="container">
		<h3>greeting.jsp에서 출력한 메시지입니다.</h3>
		<br>
		<% 
			out.println(request.getParameter("name") + "님 환영합니다.<br>");
			out.println("오늘은 " + request.getParameter("date") + "입니다.");
		%>
	</div>
</body>
</html>