<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
	<meta charset="UTF-8">
	<title>include_action</title>
	<style>
		table {margin:auto;}
		h1 {text-align:center;}
	</style>
</head>
<body>
	<div>
	<h1>Include Action Practice</h1>
	<HR>
	<table>
		<tr>
			<td width=60%>
				<jsp:include page="calendar.jsp">
					<jsp:param value="2017" name="YEAR"/>
					<jsp:param value="10" name="MONTH"/>
				</jsp:include>
			</td>
			<td>
				<jsp:include page="news.jsp">
					<jsp:param value="Homework" name="TASK2"/>
				</jsp:include>
			</td>
		</tr>
	</table>
	</div>
</body>
</html>