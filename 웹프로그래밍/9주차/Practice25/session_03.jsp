<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
	<!-- getLastAccessedTime은 계속 변경됨 
		계산할 날의 밀리초 / (1000 * 60 * 60 * 24) = 일
		(계산할 날의 밀리초 / (1000 * 60 * 60)) % 24 = 시
		(계산할 날의 밀리초 / (1000 * 60)) % 60 = 분
		(계산할 날의 밀리초 / 1000) % 60 = 초	-->
	세션이 생성된 후 <%= (session.getLastAccessedTime() - session.getCreationTime()) / 1000 % 60 %> 초후가 지났습니다.
</body>
</html>