<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
		* {font-family:'굴림';}
</style>
</head>
<body>

	<%
		Enumeration<String> e = request.getParameterNames();
	
		out.println("<h3>전달된 파라미터 이름들</h3>");
		
		while(e.hasMoreElements()){
			String s = e.nextElement();
			out.println(s);
			out.println("<br>");
		}
			
		out.println("<hr>");
	%>
	
	<%= "타입 : " + request.getParameter("type") + "<br>" %>
	<%= "아이디 : " + request.getParameter("strID") + "<br>" %>
	<%= "패스워드 : " + request.getParameter("strPwd") %>


</body>
</html>