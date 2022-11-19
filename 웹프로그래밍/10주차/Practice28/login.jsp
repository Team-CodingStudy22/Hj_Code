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
<form method=post action="checker.jsp">
<%
	String user = (String)session.getAttribute("user");

	if (user != null){
	%> <%=user %>님 환영합니다.
			<br><br>
			<input type="hidden" name="action" value="logout">
			<input type="submit" value="로그아웃">
	<% 			
	} 
	 else {%>
		<table>
		<tr>
			<td>
			아이디 : <input type = "text" name = "user">
			</td>
		</tr>
		<tr>
			<td>
			비밀번호 : <input type = "text" name = "pwd">
			</td>
		</tr>
		<tr>
			<td>
			<input type="hidden" name="action" value="login">
			<input type="submit" value="로그인">
			</td>
		</tr>
		</table>
<% } %>
</form>
</body>
</html>
