<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>include</title>
</head>
<body>
<div align="center">
	<h2>include 지시어 연습</h2>
<hr>
<p>
<table border="0" cellpadding=5 cellspacing=1>
	<tr>
		<td><font size = -1><%@include file="calendar.jsp" %></font></td>
		<td width ="20">&nbsp;</td>
		<td><font size = -1><%@include file="news.jsp" %></font></td>
	</tr>
</table>
</div>
</body>
</html>