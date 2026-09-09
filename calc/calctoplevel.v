module calctoplevel (
	input		clk_clk,
	input		reset_reset_n,
	output	[14:0]	memory_mem_a,
	output	[2:0]	memory_mem_ba,
	output		memory_mem_ck,
	output		memory_mem_ck_n,
	output		memory_mem_cke,
	output		memory_mem_cs_n,
	output		memory_mem_ras_n,
	output		memory_mem_cas_n,
	output		memory_mem_we_n,
	output		memory_mem_reset_n,
	inout	[31:0]	memory_mem_dq,
	inout	[3:0]	memory_mem_dqs,
	inout	[3:0]	memory_mem_dqs_n,
	output		memory_mem_odt,
	output	[3:0]	memory_mem_dm,
	input		memory_oct_rzqin
);










    soc_system u0 (
        .clk_clk            (clk_clk),            //    clk.clk
        .memory_mem_a       (memory_mem_a),       // memory.mem_a
        .memory_mem_ba      (memory_mem_ba),      //       .mem_ba
        .memory_mem_ck      (memory_mem_ck),      //       .mem_ck
        .memory_mem_ck_n    (memory_mem_ck_n),    //       .mem_ck_n
        .memory_mem_cke     (memory_mem_cke),     //       .mem_cke
        .memory_mem_cs_n    (memory_mem_cs_n),    //       .mem_cs_n
        .memory_mem_ras_n   (memory_mem_ras_n),   //       .mem_ras_n
        .memory_mem_cas_n   (memory_mem_cas_n),   //       .mem_cas_n
        .memory_mem_we_n    (memory_mem_we_n),    //       .mem_we_n
        .memory_mem_reset_n (memory_mem_reset_n), //       .mem_reset_n
        .memory_mem_dq      (memory_mem_dq),      //       .mem_dq
        .memory_mem_dqs     (memory_mem_dqs),     //       .mem_dqs
        .memory_mem_dqs_n   (memory_mem_dqs_n),   //       .mem_dqs_n
        .memory_mem_odt     (memory_mem_odt),     //       .mem_odt
        .memory_mem_dm      (memory_mem_dm),      //       .mem_dm
        .memory_oct_rzqin   (memory_oct_rzqin),   //       .oct_rzqin
        .reset_reset_n      (reset_reset_n)       //  reset.reset_n
    );


endmodule
