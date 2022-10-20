<%@ page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
	<div>
		<%= request.getParameter("src") %>에서 전달된 내용입니다.
		<br>
		page_control_04.jsp에서 출력합니다.
		<hr>
		넘겨받은 파라미터들 
		<br>
		<% 
			Enumeration<String> e = request.getParameterNames();
			
			while(e.hasMoreElements()){
				String s = e.nextElement();
				out.println(s + " : " + request.getParameter(s));
				out.println("<br>");
			}
		%>
		<hr>
		안녕하세요. <%= request.getParameter("username") %>님. 반갑습니다.
		<hr>
	</div>
</body>
</html>