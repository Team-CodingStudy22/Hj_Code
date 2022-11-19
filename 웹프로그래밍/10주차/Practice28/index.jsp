<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<div>
	<h2 align="center">Alice in Wonderland</h2>
	<table>
		<tr>
			<td align="right">
				<jsp:include page = "viewer.jsp"/>
			</td>
			<td align = "left">
				<jsp:include page = "login.jsp"/>
			</td>
		</tr>
	</table>
</div>
</body>
</html>
