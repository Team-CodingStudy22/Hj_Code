<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import="java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%! 
		public String parseDay(int cnt, String day){
			if(cnt % 7 == 0)
				return "<font color='blue'>" + day + "</font>";
			else if(cnt % 7 == 1) 
				return "<font color='red'>" + day + "</font>";
			else
				return day;
		}
%>
<html>
<head>
	<meta charset="UTF-8">
	<style>
		* {font-family:굴림; font-weight:bold}
		h3 {text-align:right;}
		table, tr, td {
			border: 1px solid #444444;
		    margin:auto;
		    text-align:center;
		    border-collapse: collapse;
		    width: 500px;
		}
	</style>
</head>
<body>
<table>
<% 
	Calendar today = Calendar.getInstance();
	int year = today.get(Calendar.YEAR);
	int month = today.get(Calendar.MONTH) + 1;
	int day = today.get(Calendar.DATE);
	
	out.println("<h3>" + year + "-" + month + "-" + day);
	
	Calendar cal = Calendar.getInstance();
	cal.set(2022, Calendar.OCTOBER, 1);
	int start = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	out.println("<tr>");
	out.println("<td style='color:red'>"+"일");
	out.println("<td>" + "월");
	out.println("<td>" + "화");
	out.println("<td>" + "수");
	out.println("<td>" + "목");
	out.println("<td>" + "금");
	out.println("<td style='color:blue'>" + "토");
	
	int i; day = 1;
	out.println("<tr>");
	for (i=0; i<start-1; i++)
		out.println("<td>" + "&nbsp");
	
	for (i=start; i<=7; i++) {
		out.println("<td>" + parseDay(i, Integer.toString(day)));
		day++;
	}
	
	i=0;
	while(day !=(end+1)){
		if(i%7==0) 
			out.println("<tr>");
		out.println("<td>" + parseDay(i+1, Integer.toString(day)));
		i++; day++;
	}
	
	while(i%7!=0){
		out.println("<td>");
		i++;
	}
%>
</table>
</body>
</html>