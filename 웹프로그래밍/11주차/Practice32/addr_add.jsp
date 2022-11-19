<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jwbook.ch07.*" %>
<!DOCTYPE html>
<% request.setCharacterEncoding("UTF-8"); %>

<jsp:useBean id="addr" class="jwbook.ch07.AddrBean" />
<jsp:setProperty name="addr" property="*"/>
<jsp:useBean id="am" class="jwbook.ch07.AddrManager" scope="application"/>
<jsp:useBean id="an" class="jwbook.ch07.AddrManager" scope="application"/>
<jsp:useBean id="ap" class="jwbook.ch07.AddrManager" scope="application"/>
<jsp:useBean id="aj" class="jwbook.ch07.AddrManager" scope="application"/>
<%
	am.add(addr);
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset="UTF-8">
</head>
<body>
<div align="center">
	<h2>등록내용</h2>
	이름 : <%= addr.getUsername() %><P>
	전화번호 : <%= addr.getTel() %><P>
	이메일 : <%= addr.getEmail() %><P>
	성별 : <%= addr.getGender() %><P>
	그룹 : <%= addr.getGroup() %>
	<hr>
	<a href="addr_list.jsp">전체 목록 보기</a> &nbsp;
	<a href="addr_list_group.jsp">그룹별 목록 보기</a>
</div>
</body>
</html>