<!-- 컴퓨터학과 20210779 나현지 -->
<!-- Chrome 환경에 최적화되어 있음. -->
<%@ page import = "java.util.*" language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<style>
		table, td, th {
    		border-collapse: collapse;
			margin:auto;
		}
      	.text {
			border: none;
			box-shadow: 1.5px 1.5px #91918e inset;
			background-color: #ffff99;
		}
	</style>
</head>
<body>
	<img src="image/eclass_title.jpg" width=100%>
	<h1 align="center">로그인</h1>
	 <hr>
	 <form name=frm1 action=result.jsp method=POST>
		<table>
			<tr>
	        	<td rowspan="5">
	        		<img src="image/eclass_logo.png">
	        	</td>
	        	<th colspan="2">
	        		회원님의 아이디와 비밀번호를 정확히 입력하세요.
	        	</th>
	        </tr>
	        
	        <tr>
	        	<td></td>
				<td>	
					<select name=type>
							<option value = "학부생" selected>학부생</option>
							<option value = "대학원생">대학원생</option>
							<option value = "교직원">교직원</option>
					</select>
				</td>
	        </tr>	
	       
	        <tr>
	        	<td class="id">아이디</td>
	        	<td>
	        		<input type="text" class="text" name=strID size=15 maxlength=15>
	        	</td>	
	        </tr>
	        
	        <tr>
	        	<td class="pwd">비밀번호</td>
	        	<td>
	        		<input type="password" class="text" name=strPwd size=15 maxlength=15>
	        	</td>	
	        </tr>
	        
	        <tr>
	        	<td colspan="2">
	        		<input type="submit" value="로그인" class="login" onclick="document.location='result.jsp'">
	        		<input type="button" value="가입하기">
	        	</td>
	        </tr>
		</table>			
	 </form>
</body>
</html>