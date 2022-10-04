<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>notice</title>
	<style>
	 * {font-family: serif;}
	 table,td,th {
	 	width:700px;
    	margin:auto;
	 }
	 .top{background-color:#fedab9;height:40px;}
	 .bottom{background-color:#ffeed4; height:300px;}
	</style>
</head>
<body>
	<form>
	<div>
		<img src="image/eclass_title.jpg" width=100%>
	</div>
	<table>
		<tr>
			<th class="top">오류가 발생했습니다</th>
		</tr>
		<tr>
			<th class="bottom" colspan="2">
				<input type="image" src ="image/flower.gif">
				<br><br>
				오류 발생시간: <%= new java.util.Date() %>
				<br><br>
				최대한 빨리 조치하겠습니다.
			</th>
		</tr>
	</table>
	</form>
</body>
</html>