<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ch06: page_control.jsp</title>
<style>
	#box {border : 1px solid green}
</style>
</head>
<body>
	<form method = post action=page_control_02.jsp>
		아이디: <input type=text id=box name=username> 비밀번호: <input type=text id=box name=password> 
		<input type=submit value="forward 전송">
	</form>
	
	<form method = post action=page_control_03.jsp>
		아이디: <input type=text id=box name=username> 비밀번호: <input type=text id=box name=password> 
		<input type=submit value="sendRedirect 전송">
	</form>
</body>
</html>