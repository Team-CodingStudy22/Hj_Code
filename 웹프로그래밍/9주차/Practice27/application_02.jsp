<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
	<%
			Integer count = (Integer)application.getAttribute("count");
			int time = Integer.parseInt(request.getParameter("time"));
			session.setMaxInactiveInterval(time*60);
			if(count==null)
				count = new Integer(0);
			count = count + 1;
			application.setAttribute("count", count);
		%>
	
	<%= request.getParameter("username") %>님 환영합니다.
	<br><br>
	세션 ID : <%= session.getId() %>
	<br>
	세션 지속시간(default) : <%= session.getMaxInactiveInterval() %> 초
	<br><br>
	오늘의 접속자수 : <%= count %>
</body>
</html>