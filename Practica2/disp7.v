module disp7(
	input [2:0] input_number,
	output reg [6:0] display_output
);

	always @(input_number)
	begin
			case(input_number)
			  3'b000: // f
				  display_output = 7'b0001110;
			  3'b001: // p
			     display_output = 7'b0001100;
			  3'b010: // g
			     display_output = 7'b0000010;
			  3'b011: // a
				  display_output = 7'b0001000;
				3'b111: // vacio
				  display_output = 7'b1111111;
			endcase
	end
endmodule
