<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import="java.util.Calendar" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<%
	int year = 1919;
	int month = 3;
	int i;
	int day = 1;
	
	Calendar cal = Calendar.getInstance();
	cal.set(year, month-1, 1);
	int week = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	out.println("<h2>" + year + "년 " + month + "월" + "</h2>");
	out.println("<hr>");

	for (i=0; i<week-1; i++)
		out.println("&nbsp");
	for (i=week; i<=7; i++)
		out.println("  " + (day++) + "  ");
	
	i=0;
	while(day!=end+1){
		if(i%7==0)
			out.println("<br>");
		out.println(" " + (day++) + " ");
		i++;
	}
%>
</body>
</html>