<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<form method=post action=application_02.jsp>
	<table>
		<tr>
			<td>
				아이디: 
			</td>
			<td>
			<input type="text" name="username">
			</td>
		</tr>
		<tr>
			<td>
				원하는 세션 지속시간 (분):
			</td>
			<td>
				<input type="text" name="time">
			</td>
		</tr>
		</table>
		<br>
		<input type="submit" value="로그인">
		<input type="button" value="취소">

	<%
		application.setAttribute("count", 1);
	%>
</form>

</body>
</html>