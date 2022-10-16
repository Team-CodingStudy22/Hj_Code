<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>news</title>
	<style>
		p {font-size:40px;}
	</style>
</head>
<body>
	<h1>오늘의 일정</h1>
	<hr>
<% 
	String task1 = request.getParameter("TASK1");
	String task2 = request.getParameter("TASK2");
	
	if(task1 == null)
		task1 = "일정 없음";
	else if(task2 == null)
		task2 = "일정 없음";
%>
	<ol>
		<li><%= task1 %></li>
		<li><%= task2 %></li>
	</ol>
</body>
</html>