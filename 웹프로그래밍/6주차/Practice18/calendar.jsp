<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import="java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Calendar</title>
</head>
<body>
<%
	int year,month,i,j;
	int day = 1;
	Calendar cal = Calendar.getInstance();
	
	if(request.getParameter("YEAR") != null && request.getParameter("MONTH") != null) {
		year = Integer.parseInt(request.getParameter("YEAR"));
		month = Integer.parseInt(request.getParameter("MONTH"));
	}
	else {
		year = cal.get(Calendar.YEAR);
		month = cal.get(Calendar.MONTH) + 1;	
	}
		
	cal.set(year, month-1, 1);
	int start = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	out.println("<h2>" + year + "년 " + month + "월" + "</h2>");
	out.println("<hr>");

	for (i=0; i<start-1; i++)
		out.println("&nbsp&nbsp&nbsp&nbsp");
	for (i=start; i<=7; i++)
		out.println("&nbsp&nbsp" + (day++) + "&nbsp&nbsp");
	
	i=0;
	while(day!=end+1){
		if(i%7==0)
			out.println("<br>");
		out.println("&nbsp&nbsp" + (day++) + "&nbsp&nbsp");
		i++;
	}
%>
</body>
</html>