<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 09</title>
</head>
<body>
	<%@page info="Practice 08"%>
	<% String s = "Hello, Welcome to JSP World! Let's go!"; String t = "JSP";
	out.println("입력되어 있는 문자열 : " + s);  out.println("<br>");
	out.println("문자열의 길이 : "+ s.length());  out.println("<br>");	
	out.println("'" + t + "'" + "라는 문자의 위치 : " + s.indexOf(t)); out.println("<br>");
	out.println("모두 소문자로 변경 : " + s.toLowerCase()); out.println("<br>");
	out.println("모두 대문자로 변경 : " + s.toUpperCase());
	%>
	
	
	



</body>
</html>