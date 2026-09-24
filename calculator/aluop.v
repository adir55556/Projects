module aluop(
input wire signed [31:0] A,
input wire signed [31:0] B,
input wire [2:0] OP,
output reg signed [31:0] SUM
);

localparam OP_PLUS =3'b000;
localparam OP_MINUS=3'b001;
localparam OP_DIVIDE=3'b010;
localparam OP_MULTIPLY=3'b011;
localparam OP_REMINDER=3'b100;



always @(*) begin
	case(OP)
	OP_PLUS: 
			 SUM= A + B;
			 		 
	OP_MINUS:  
			 SUM= A - B;
			 
	OP_DIVIDE: 
			 SUM= A / B;
	
	OP_MULTIPLY: 
			 SUM= A * B;
				 
	OP_REMINDER:  	
			 SUM= A % B;
	
	default:  begin 
			SUM = 0;
	
	end
	endcase
	end
	endmodule
	