<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%!
	String[] list = {};
	String[] mChoices = {"hobby"};

%>
<%

	String[] hobbyNames = {"뉴스", "맛집", "책", "영화", "여행"};
	String[] telCompany = {"010", "011", "017", "070"};
	String[] gNames = {"남", "여"};
	//파라미터 이름들 추출
	Enumeration<String> e = request.getParameterNames();
	
	//여러 값을 갖는 hobby 
	String hobby[] = request.getParameterValues("hobby");

	while(e.hasMoreElements()){
		String s = e.nextElement();
		
		if(s.equals("hobby")){
			out.println(s + " : " );
			for(int i=0; i<hobby.length; i++)
				out.println(hobby[i] + "/");
		}
		else
			out.println(s + " : " + request.getParameter(s));
		out.println("<br>");
	}
	
	out.println("<hr>");
	out.println("<h2>Processing Parameters</h2>");
	
	Enumeration<String> t = request.getParameterNames();
	
	while(t.hasMoreElements()){
		String q = t.nextElement();
		
		if(q.equals("gender"))
			out.println(q + " : " + gNames[Integer.parseInt(request.getParameter(q))] );
		
		else if(q.equals("phone1"))
			out.println(q + " : " + telCompany[Integer.parseInt(request.getParameter(q))] );
		
		else if(q.equals("hobby")){
			out.println(q + " : " );
			for(int i=0; i<hobby.length; i++)
				out.println(hobbyNames[Integer.parseInt(hobby[i])] + "/");
		}
		
		else out.println(q + " : " + request.getParameter(q));
		out.println("<br>");
	}
	
	
	
%>


</body>
</html>