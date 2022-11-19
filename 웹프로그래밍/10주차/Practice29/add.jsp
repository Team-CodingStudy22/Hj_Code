<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%><%@ page import="java.util.*" %>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<%
	String name = request.getParameter("name");
	String phone = request.getParameter("phone");

	if(name != null)
		session.setAttribute("name", name);
	if(phone != null)
		session.setAttribute("phone", phone);
%>
<body>
<div align="center">
<h2>주소록</h2>
<hr>
<%
	name = (String)session.getAttribute("name");
	phone = (String)session.getAttribute("phone");
	
	ArrayList<String> list = (ArrayList<String>)application.getAttribute("addrbook");
	
	if(list == null){
		list = new ArrayList<String>();
	}

	list.add(name + "," + phone);
	application.setAttribute("addrbook", list);
	
	if(list!=null) {
		int count = 1;
		for(String student:list){
			out.println(count + ". "+ student + "<br>");
			count++;
		}
	}
%>
</div>
</body>
</html>