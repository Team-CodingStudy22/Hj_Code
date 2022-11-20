package jwbook.ch07;

public class Calculator {
	
	private int op1;
	private int op2;
	private String operator;
	
	public int getOp1() {
		return op1;
	}
	public void setOp1(int op1) {
		this.op1 = op1;
	}
	public int getOp2() {
		return op2;
	}
	public void setOp2(int op2) {
		this.op2 = op2;
	}
	public String getOperator() {
		return operator;
	}
	public void setOperator(String operator) {
		this.operator = operator;
	}
	
	public int calc() {
		int result = 0;
		
		if(operator.equals("+"))
	 		result = op1 + op2;
	 	else if(operator.equals("-"))
	 		result = op1 - op2;
	 	else if(operator.equals("*"))
	 		result = op1 * op2;
 		else if(operator.equals("/"))
	 		result = op1 / op2;
	 		
	 	return result;
	
	}
}