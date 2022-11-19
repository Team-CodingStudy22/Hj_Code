<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
	<%
	String action = request.getParameter("action");
	
	if (action.equals("login")) {
		String user = request.getParameter("user"); 
		String pwd = request.getParameter("pwd"); 
		
		if(user != null && pwd.equals("hatter"))
			session.setAttribute("user", user);
	}
	else {
		session.invalidate();
	}
	response.sendRedirect("index.jsp");
%>
</body>
</html>
