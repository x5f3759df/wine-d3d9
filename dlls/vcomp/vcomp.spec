@ stub _vcomp_atomic_add_i1
@ stub _vcomp_atomic_add_i2
@ cdecl _vcomp_atomic_add_i4(ptr long)
@ stub _vcomp_atomic_add_i8
@ cdecl _vcomp_atomic_add_r4(ptr float)
@ cdecl _vcomp_atomic_add_r8(ptr double)
@ stub _vcomp_atomic_and_i1
@ stub _vcomp_atomic_and_i2
@ cdecl _vcomp_atomic_and_i4(ptr long)
@ stub _vcomp_atomic_and_i8
@ stub _vcomp_atomic_div_i1
@ stub _vcomp_atomic_div_i2
@ cdecl _vcomp_atomic_div_i4(ptr long)
@ stub _vcomp_atomic_div_i8
@ cdecl _vcomp_atomic_div_r4(ptr float)
@ cdecl _vcomp_atomic_div_r8(ptr double)
@ stub _vcomp_atomic_div_ui1
@ stub _vcomp_atomic_div_ui2
@ cdecl _vcomp_atomic_div_ui4(ptr long)
@ stub _vcomp_atomic_div_ui8
@ stub _vcomp_atomic_mul_i1
@ stub _vcomp_atomic_mul_i2
@ cdecl _vcomp_atomic_mul_i4(ptr long)
@ stub _vcomp_atomic_mul_i8
@ cdecl _vcomp_atomic_mul_r4(ptr float)
@ cdecl _vcomp_atomic_mul_r8(ptr double)
@ stub _vcomp_atomic_or_i1
@ stub _vcomp_atomic_or_i2
@ cdecl _vcomp_atomic_or_i4(ptr long)
@ stub _vcomp_atomic_or_i8
@ stub _vcomp_atomic_shl_i1
@ stub _vcomp_atomic_shl_i2
@ cdecl _vcomp_atomic_shl_i4(ptr long)
@ stub _vcomp_atomic_shl_i8
@ stub _vcomp_atomic_shr_i1
@ stub _vcomp_atomic_shr_i2
@ cdecl _vcomp_atomic_shr_i4(ptr long)
@ stub _vcomp_atomic_shr_i8
@ stub _vcomp_atomic_shr_ui1
@ stub _vcomp_atomic_shr_ui2
@ cdecl _vcomp_atomic_shr_ui4(ptr long)
@ stub _vcomp_atomic_shr_ui8
@ stub _vcomp_atomic_sub_i1
@ stub _vcomp_atomic_sub_i2
@ cdecl _vcomp_atomic_sub_i4(ptr long)
@ stub _vcomp_atomic_sub_i8
@ cdecl _vcomp_atomic_sub_r4(ptr float)
@ cdecl _vcomp_atomic_sub_r8(ptr double)
@ stub _vcomp_atomic_xor_i1
@ stub _vcomp_atomic_xor_i2
@ cdecl _vcomp_atomic_xor_i4(ptr long)
@ stub _vcomp_atomic_xor_i8
@ cdecl _vcomp_barrier()
@ stub _vcomp_copyprivate_broadcast
@ stub _vcomp_copyprivate_receive
@ cdecl _vcomp_enter_critsect(ptr)
@ cdecl _vcomp_flush()
@ cdecl _vcomp_for_dynamic_init(long long long long long)
@ stub _vcomp_for_dynamic_init_i8
@ cdecl _vcomp_for_dynamic_next(ptr ptr)
@ stub _vcomp_for_dynamic_next_i8
@ cdecl _vcomp_for_static_end()
@ cdecl _vcomp_for_static_init(long long long long ptr ptr ptr ptr ptr)
@ stub _vcomp_for_static_init_i8
@ cdecl _vcomp_for_static_simple_init(long long long long ptr ptr)
@ stub _vcomp_for_static_simple_init_i8
@ varargs _vcomp_fork(long long ptr)
@ cdecl _vcomp_get_thread_num()
@ cdecl _vcomp_leave_critsect(ptr)
@ stub _vcomp_master_barrier
@ cdecl _vcomp_master_begin()
@ cdecl _vcomp_master_end()
@ stub _vcomp_ordered_begin
@ stub _vcomp_ordered_end
@ stub _vcomp_ordered_loop_end
@ stub _vcomp_reduction_i1
@ stub _vcomp_reduction_i2
@ stub _vcomp_reduction_i4
@ stub _vcomp_reduction_i8
@ stub _vcomp_reduction_r4
@ stub _vcomp_reduction_r8
@ stub _vcomp_reduction_u1
@ stub _vcomp_reduction_u2
@ stub _vcomp_reduction_u4
@ stub _vcomp_reduction_u8
@ cdecl _vcomp_sections_init(long)
@ cdecl _vcomp_sections_next()
@ cdecl _vcomp_set_num_threads(long)
@ cdecl _vcomp_single_begin(long)
@ cdecl _vcomp_single_end()
@ cdecl omp_destroy_lock(ptr)
@ cdecl omp_destroy_nest_lock(ptr) omp_destroy_lock
@ cdecl omp_get_dynamic()
@ cdecl omp_get_max_threads()
@ cdecl omp_get_nested()
@ cdecl omp_get_num_procs()
@ cdecl omp_get_num_threads()
@ cdecl omp_get_thread_num()
@ stub omp_get_wtick
@ cdecl omp_get_wtime()
@ cdecl omp_in_parallel()
@ cdecl omp_init_lock(ptr)
@ cdecl omp_init_nest_lock(ptr) omp_init_lock
@ cdecl omp_set_dynamic(long)
@ cdecl omp_set_lock(ptr)
@ cdecl omp_set_nest_lock(ptr)
@ cdecl omp_set_nested(long)
@ cdecl omp_set_num_threads(long)
@ cdecl omp_test_lock(ptr)
@ cdecl omp_test_nest_lock(ptr)
@ cdecl omp_unset_lock(ptr)
@ cdecl omp_unset_nest_lock(ptr)
