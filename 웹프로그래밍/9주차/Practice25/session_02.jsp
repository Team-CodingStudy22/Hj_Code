<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
	<%= request.getParameter("username") %>님 환영합니다.
	<br><br>
	세션 ID : <%= session.getId() %>
	<br>
	세션 지속시간(default) : <%= session.getMaxInactiveInterval() %> 초
	<br><br>
	<a href="session_03.jsp" target="_blank"> session_03.jsp로 가기 </a>
</body>
</html>