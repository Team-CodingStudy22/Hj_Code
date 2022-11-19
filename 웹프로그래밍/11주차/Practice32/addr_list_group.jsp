<%@ page language="java" contentType="text/html; charset=UTF-8" import="jwbook.ch07.*" import="java.util.*"
    pageEncoding="UTF-8"%>
    
<!DOCTYPE html>
<jsp:useBean id="am" class="jwbook.ch07.AddrManager" scope="application"/>
<jsp:useBean id="an" class="jwbook.ch07.AddrManager"/>
<jsp:useBean id="ap" class="jwbook.ch07.AddrManager"/>
<jsp:useBean id="aj" class="jwbook.ch07.AddrManager"/>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset="UTF-8">
</head>
<body>
	<div align=center>
		<h2>주소록</h2>
		<hr>
		<a href="addr_form.html">주소추가</a><P>
		<table border=1 width=500>
			<tr>
				<td>이름</td>
				<td>전화번호</td>
				<td>이메일</td>
				<td>성별</td>
				<td>그룹</td>
			</tr>
			<%
				for(AddrBean ab : am.getAddrList()) {
					if(ab.getGroup().equals("가족")) 	
						an.add(ab);
					else if(ab.getGroup().equals("친구"))
						ap.add(ab);
					else
						aj.add(ab);
				}
			
				for(AddrBean ab : an.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getGender() %></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<%
				}
				
				for(AddrBean ab : ap.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getGender() %></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<% 
}
				
				for(AddrBean ab : aj.getAddrList()) {
			%>
				<tr>
				<td><%=ab.getUsername() %></td>
				<td><%=ab.getTel() %></td> 
				<td><%=ab.getEmail() %></td>
				<td><%=ab.getGender() %></td>
				<td><%=ab.getGroup() %></td>
				</tr>
			<%
				}
			%>
				
		</table>
	</div>
</body>
</html>