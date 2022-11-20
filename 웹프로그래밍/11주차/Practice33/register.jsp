<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%><%@ page import="java.util.*" %>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<jsp:useBean id="login" class="jwbook.ch07.LoginBean" scope="page"/>
<jsp:setProperty name="login" property="*"/>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset="UTF-8">
<%
	String check = "";
	if(login.isGrownUp() == true)
		check = "성인";
	else
		check = "청소년";
	
	String sex = "";
	if(login.getGender().equals(0))
		sex = "남성";
	else
		sex = "여성";
%>
</head>
<body>
<div align="center">
	<h2>등록내용</h2>
	이름 : <%= login.getId() %><P>
	패스워드 : <%= login.getPw() %><P>
	이메일 : <%= login.getEmail() %><P>
	성별 : <%= login.getGender() %><P>
	생일 : <%= login.getBirth() %>
	<hr>
	<%=login.getId() %>씨는 <%= sex %>이고, <%=check %>입니다.
</div>
</body>
</html>