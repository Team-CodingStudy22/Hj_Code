<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import="java.util.Calendar" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice14</title>
</head>
<body>
<%!
	String change_day(int day_num){
		switch(day_num) {
			case(1): return "일요일"; 
			case(2): return "월요일"; 
			case(3): return "화요일"; 
			case(4): return "수요일"; 
			case(5): return "목요일"; 
			case(6): return "금요일"; 
			case(7): return "토요일";
			default: return "오류";
	}
}
%>
<%
	Calendar cal = Calendar.getInstance();
	cal.set(2018, Calendar.OCTOBER, 8);
	
	int year = cal.get(Calendar.YEAR);
	int month = cal.get(Calendar.MONTH);
	int date = cal.get(Calendar.DATE);
	String day = change_day(cal.get(Calendar.DAY_OF_WEEK));

	out.println("오늘은 " + year + "년 " + (month+1) + "월 " + date + "일 " + day + "입니다.<br><br>");
	
	int start = cal.getMinimum(Calendar.DATE);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	out.println("이번 달은 " + start + "일부터 시작하여 " + end + "일에 끝납니다.<br><br>");
	
	cal.set(2001, Calendar.JANUARY, 6);
	year = cal.get(Calendar.YEAR);
	month = cal.get(Calendar.MONTH);
	date = cal.get(Calendar.DATE);
	day = change_day(cal.get(Calendar.DAY_OF_WEEK));

	out.println("내 생일 " + year + "년 " + (month+1) + "월 " + date + "일은 " + day + "입니다.");
%>
</body>
</html>