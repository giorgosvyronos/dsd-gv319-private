transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/e2/gv319-repo/system_template_de1_soc/software {/home/e2/gv319-repo/system_template_de1_soc/software/lpm_mult1.v}
vlog -vlog01compat -work work +incdir+/home/e2/gv319-repo/system_template_de1_soc/software/db {/home/e2/gv319-repo/system_template_de1_soc/software/db/mult_b8n.v}

vlog -vlog01compat -work work +incdir+/home/e2/gv319-repo/system_template_de1_soc/software/.. {/home/e2/gv319-repo/system_template_de1_soc/software/../testbench_1.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  tb

add wave *
view structure
view signals
run -all
