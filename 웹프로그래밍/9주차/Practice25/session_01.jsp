<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<form method=post action=session_02.jsp>
	아이디:
	<input type="text" name="username">
	<br><br>
	비밀번호:
	<input type="text" name="passwd">
	<br><br>
	<input type="submit" value="로그인">
	<input type="button" value="취소">
</form>
</body>
</html>