module componentalu(
input wire clk,
input wire rst,
input wire write,
input wire [31:0] writedata,
input wire read,
output reg [31:0] readdata 
);

localparam WRITEA = 2'b00;
localparam WRITE_B = 2'b01;
localparam WRITE_OP= 2'b10;

wire signed [31:0] result;
reg  [1:0] state = 2'b00; 
reg  signed [31:0] arg_A=32'b0;
reg  signed [31:0] arg_B=32'b0;
reg  [2:0]  arg_OP=3'b0;


aluop aluop_inst
(
	.A(arg_A) ,	// input [31:0] A_sig
	.B(arg_B) ,	// input [31:0] B_sig
	.OP(arg_OP) ,	// input [2:0] OP_sig
	.SUM(result) 	// output [31:0] SUM_sig
);

always @(posedge clk or negedge rst) begin 
	if (!rst) begin 
			arg_A <= 32'b0;
			arg_B <=32'b0;
			arg_OP <= 3'b0;
			state <= WRITEA;
			
	end 
	else begin 
	
		case (state)
			WRITEA: begin 
			  if (write) begin 
						arg_A <= writedata;
						state <= WRITE_B;
						
			 end else begin 
					state <= WRITEA;
			 end
			 end
			 
			WRITE_B: begin
			 if (write) begin
				arg_B <= writedata;
			 
				state <= WRITE_OP;
			 end
			 end
			 
			WRITE_OP: begin 
			 if (write) begin
				arg_OP <= writedata[2:0];
				state <= WRITEA;
			 end
			 end
			default: begin 
				state <= WRITEA;
	
	end
	endcase
	end
	end
	
	always @(*) begin 
		if(read) begin 
		readdata = result;
		
	end else begin 
		readdata = 32'b0;
	
	end
	end
	endmodule
