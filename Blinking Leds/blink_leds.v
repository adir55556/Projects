module blink_leds(

input wire clk,
input wire rst,
input wire write,
input wire [31:0] writedata,
input	wire read,
input wire chipselect,

output [31:0] readdata,
output [7:0] LEDS
);
reg [31:0] readdata_reg;
reg [7:0] leds_reg;



always @(posedge clk or negedge rst) begin 
		if(!rst) begin 
		 leds_reg <=8'b0;
	end
		else if(chipselect && write) begin 
			leds_reg <= writedata[7:0]; 
			
	end
	end
	
always @(*) begin 
		if(chipselect && read) begin 
		readdata_reg = {24'b0 ,leds_reg};
		
	end
		else begin 
		readdata_reg = 32'b0;
		
	end
   end	
	
	assign readdata = readdata_reg;
	assign LEDS = leds_reg;
	
	endmodule
	
			
			
			
			
			
			
			
			
			