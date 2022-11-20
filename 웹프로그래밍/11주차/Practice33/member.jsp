<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%><%@ page import="java.util.*" %>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset="UTF-8">
<style>
		 * {font-family: '굴림', serif;}
		  table,td,th {
		 	border: 1px solid #444444;
	    	border-collapse: collapse;
	    	margin:auto;
	 }
	  th{background-color:#ececec;}
	</style>
</head>
<body>
<form name=form1 method="post" action=register.jsp>
	<img src="image/eclass_title.jpg" width=100%>
	<table>
	<tr>
		<th colspan="2"><b>회원 가입</b></th>
	</tr>

	<tr>
		<th>아이디</th>
	<td>
		<input type=text name=id size=15 maxlength=20>
	    <input type="image" src ="image/check.gif" class="imageAlign">
    </td>
	</tr>
	
	<tr>
	<th>패스워드</th>
	<td>
		<input type=text name=pw size=15 maxlength=20>
    </td>
	</tr>
	
	<tr>
	<th>성별</th>
	<td>
		<input type=radio name=gender value=0>남
		<input type=radio name=gender value=1 checked>여
	</td>
	</tr>
	
	<tr>
	<th>국적</th>
	<td>
		<input type=text name=country size=20 maxlength=20 value="대한민국">
		<input type=button value="국적변경">
	</td>
	</tr>
	
	<tr>
	<th>휴대폰</th>
	<td>
		<select name=phone>
			<option value=0 selected>010</option>
			<option value=1>010</option>
			<option value=2>011</option>
			<option value=3>070</option>
			<option value=4>080</option>
		</select>
		-
		<input type=text name=id size=5 maxlength=4>
		-
		<input type=text name=id size=5 maxlength=4>
	</td>
	</tr>
	
	<tr>
	<th>이메일</th>
	<td>
		<input type=text name=email size=40 maxlength=20>
	</td>
	</tr>
	
	<tr>
	<th>생일</th>
	<td>
		<input type=text name=birth size=15 maxlength=20 value=연도-월-일>
	</td>
	</tr>
	
	<tr>
	<th>관심분야</th>
	<td>
		<input type=checkbox name=hobby value=0>뉴스
		<input type=checkbox name=hobby value=1 checked>맛집
		<input type=checkbox name=hobby value=2>책
		<input type=checkbox name=hobby value=3>영화
		<input type=checkbox name=hobby value=4>여행
	</td>
	</tr>
	
	<tr>
	<th>가입인사</th>
	<td>
	<textarea
			  id="textarea"
			  rows="5"
			  cols="50">회원들에게 간단한 가입인사를 남겨주세요
	</textarea>
	</td>
	</tr>
	
	<tr>
		<th>증명사진</th>
		<td>
		<input type=button value="파일 선택">
		선택된 파일 없음
		</td>
	</tr>
	
	<tr>
		<th colspan="2">
			<input type="submit" value="가입하기">
			<input type="reset" value="다시작성">
		</th>
	</tr>
	</table>
	</form>
</body>
</html>