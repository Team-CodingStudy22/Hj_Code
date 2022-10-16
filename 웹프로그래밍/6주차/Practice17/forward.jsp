<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>forward action</title>
<style>
	*{font-family:"Monospace"}
</style>
</head>
<body>
	<div><h1>greeting.jsp에서 출력한 메시지입니다.</h1></div>
	<br>
	<jsp:forward page="greeting.jsp">
		<jsp:param name="name" value="Dongduk University"/>
		<jsp:param name="date" value="2011/04/05"/>
	</jsp:forward>
</body>
</html>