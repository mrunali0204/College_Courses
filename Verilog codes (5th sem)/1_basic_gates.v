module and_gate(y,a,b);
input a,b;
output y;
assign y=a&b;
endmodule


module or_gate(y,a,b);
input a,b;
output y;
assign y=a|b;
endmodule


module not_gate(y,a);
input a;
output y;
assign y=~a;
endmodule


module nand_gate(y,a,b);
input a,b;
output y;
assign y=~(a&b);
endmodule


module nor_gate(y,a,b);
input a,b;
output y;
assign y=~(a|b);
endmodule


module xor_gate(y,a,b);
input a,b;
output y;
assign y=a^b;
endmodule