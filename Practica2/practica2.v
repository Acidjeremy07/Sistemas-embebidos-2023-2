module fpga 
(
	input clk,
	input [1:0] switch,
	input [1:0] switch1,
	output [6:0] display0,
	output [6:0] display1,
	output [6:0] display2,
	output [6:0] display3,
	output [6:0] display4,
	output [6:0] display5,
	output [6:0] display6,
	output [6:0] display7
);
	parameter frecuencia=50000000;
	reg freq_out;
	reg max_count;
	reg[22:0] count;
	reg [2:0] var0, var1, var2, var3, var4, var5, var6, var7;
	reg clk_out;
	reg [2:0] temp;

	initial begin
		count=0;
		freq_out=10;
		clk_out=0;
		max_count=frecuencia/(2*freq_out);
		var0 = 011;
		var1 = 010;
		var2 = 001;
		var3 = 000;
		var4 = 111;
		var5 = 111;
		var6 = 111;
		var7 = 111;
	end
	
  always @(posedge clk)
	 begin
			case (switch1)
				2'b00:
					freq_out = 2;
				2'b01:
					freq_out = 4;
				2'b10:
					freq_out = 6;
				2'b11:
					freq_out = 8;
			endcase
			

			if(count==max_count)begin
				//clk_out = -clk_out;
				count=0;
				if(switch[0]==0 && switch[1]==1)begin
					temp = var7;
					var7 = var6;
					var6 = var5;
					var5 = var4;
					var4 = var3;
					var3 = var2;
					var2 = var1;
					var1 = var0;
					var0 = temp;
				end
				else if(switch[0]==1 && switch[1]==0)begin
					temp = var0;
					var0 = var1;
					var1 = var2;
					var2 = var3;
					var3 = var4;
					var4 = var5;
					var5 = var6;
					var6 = var7;
					var7 = temp;
				end
			end
			else begin
				count=count+1;
			end
	 end
			disp7 disp0(
				.input_number(var0),
				.display_output(display0)
			);
			
			disp7 disp1(
				.input_number(var1),
				.display_output(display1)
			);
			
			disp7 disp2(
				.input_number(var2),
				.display_output(display2)
			);
			
			disp7 disp3(
				.input_number(var3),
				.display_output(display3)
			);
			disp7 disp4(
				.input_number(var4),
				.display_output(display4)
			);
			disp7 disp5(
				.input_number(var5),
				.display_output(display5)
			);
			disp7 disp6(
				.input_number(var6),
				.display_output(display6)
			);
			disp7 disp7(
				.input_number(var7),
				.display_output(display7)
			);
endmodule

