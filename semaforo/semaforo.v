module semaforo(
	input	wire	clk_i,		//Reloj original de 50mhz
	input	wire	rst_i,		//Reset
	input	wire	boton_1,		//Interrupcion primer semaforo
	input	wire	boton_2,		//Interrupcion segundo semaforo
	output	reg	led_r_1,	//Led rojo 		primer semaforo 
	output	reg	led_a_1,	//Led amarillo primer semaforo
	output	reg	led_v_1,	//Led verde 	primer semaforo
	output	reg	led_r_1,	//Led rojo		segundo semaforo
	output	reg	led_a_1,	//Led amarillo	segundo semaforo
	output	reg	led_v_1	//Led verde		segundo semaforo
);

//Estados del semaforo
	parameter VERDE = 0, AMARILLO = 1, ROJO = 2;
	reg[1:0]	state_1, state_2;

//Salida del divisor de frecuencia 
	wire clk1hz_w;
	
//Contadores para los tiempos de los leds y los tiempos de guardado
	reg[5:0]	counter_1, savedtime_1;
	reg[5:0]	counter_2, savedtime_2;

//Inicializacion de las variables para el sistema
	always@(posedge clk1hz_w or posedge rst_i)
	begin
		if(rst_i)
		begin 
			state_1		<= ROJO;
			state_2		<= ROJO;
			counter_1	<= 0;
			counter_2	<=	0;
		end
		else
		begin
			if(boton_1 && state_1 == VERDE && counter_1 <	6'b110111)
			begin
				state_1		<=	ROJO;
				savedtime_1	<=	6'b110111	-	counter_1;
			end
			else if(boton_2 && state_2 == VERDE && counter_2 < 6'b110111)
			begin
				state_2		<=	ROJO;
				savedtime_2	<=	6'b110111	-	counter_2;
			end
			else	
			begin
				counter_1	<=	counter_1	+	1'b1;
				counter_2	<=	counter_2	+	1'b1;
				case(counter_1)
				begin
					6'b110111:
					begin
						state_1	<=	VERDE;
					end
					6'b111100:
					begin
						state_1	<= AMARILLO;
					end
					
				endcase
			
			
			
			
			
			
endmodule 