module and_gate(y,a,b);
input a,b;
output y;
assign y=a&b;
endmodule


Testbench :

module testbench1;
wire t_y;
reg t_a, t_b;
and_gate dut(.y(t_y), .a(t_a),
.b(t_b));
initial
begin
t_a = 1'b0; t_b = 1'b0;
#5
t_a = 1'b0; t_b = 1'b1;
#5
t_a = 1'b1; t_b = 1'b0;
#5
t_a = 1'b1; t_b = 1'b1;
end
endmodule