<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>include action</title>
	<style>
		*{font-family:굴림}
		h1 {text-align:center; font-weight:900;}
	</style>
</head>
<body>
	<div><h1>include 액션 연습</h1></div>
	<hr>
	<jsp:include page="greeting.jsp">
		<jsp:param name="name" value="Dongduk University"/>
		<jsp:param name="date" value="2011/04/05"/>
	</jsp:include>
</body>
</html>