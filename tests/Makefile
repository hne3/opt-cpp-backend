all-traces: basic.vgtrace \
						meng-thesis-example.vgtrace \
						array-overflow.vgtrace \
						array-param.vgtrace \
						struct-basic.vgtrace \
						globals.vgtrace \
						string-array.vgtrace \
						structs-and-arrays.vgtrace \
						pointer-chain.vgtrace \
						typedef-test.vgtrace \
						type-qualifiers.vgtrace \
						shadowing.vgtrace \
						pointers-gone-wild.vgtrace \
						number-types.vgtrace \
						fjalar-ArraysInStructTest.vgtrace \
						fjalar-ArrayTest.vgtrace \
						fjalar-CoercePointerTest.vgtrace \
						fjalar-crazy-test-1.vgtrace \
						fjalar-FloatTest.vgtrace \
						fjalar-function-pointer.vgtrace \
						fjalar-functions.vgtrace \
						fjalar-GlobalTest.vgtrace \
						fjalar-inline-func.vgtrace \
						fjalar-IntTest.vgtrace \
						fjalar-local-ptr.vgtrace \
						fjalar-MultiDimArrayTest.vgtrace \
						fjalar-NestedStructTest.vgtrace \
						fjalar-NestedStructVarList.vgtrace \
						fjalar-pointer-levels.vgtrace \
						fjalar-PointerTest.vgtrace \
						fjalar-small-test.vgtrace \
						fjalar-StaticArraysTest.vgtrace \
						fjalar-string-arrays.vgtrace \
						fjalar-StructPtrTest.vgtrace \
						fjalar-TrivialTest.vgtrace \
						fjalar-TypedefTest.vgtrace \
						cpp-array-struct-test.vgtrace \
						cpp-class-pointers.vgtrace \
						cpp-first.vgtrace \
						cpp-object-array.vgtrace \
						cpp-virtual-method.vgtrace \
						cpp-class-basic.vgtrace \
						cpp-consts.vgtrace \
						cpp-function-types.vgtrace \
						cpp-pass-by-ref.vgtrace \
						cpp-class-date.vgtrace \
						cpp-exception.vgtrace \
						cpp-inheritance.vgtrace \
						cpp-stack-inline.vgtrace


#%: %.c
#	@gcc -ggdb -O0 -fno-omit-frame-pointer $< -o $@

#%: %.cpp
#	g++ -ggdb -O0 -fno-omit-frame-pointer $< -o $@

# use '|| true' to always return success and keep 'make' running even on errors
#%.vgtrace: % ../valgrind-3.11.0/inst/bin/valgrind
#	../valgrind-3.11.0/inst/bin/valgrind --tool=memcheck --source-filename=$<.c --trace-filename=$<.vgtrace ./$< || true


%.vgtrace: %.c ../valgrind-3.11.0/inst/bin/valgrind
	@gcc -ggdb -O0 -fno-omit-frame-pointer $< -o $(basename $@)
	@../valgrind-3.11.0/inst/bin/valgrind --tool=memcheck --source-filename=$< --trace-filename=$(basename $<).vgtrace ./$(basename $<) || true

%.vgtrace: %.cpp ../valgrind-3.11.0/inst/bin/valgrind
	@g++ -ggdb -O0 -fno-omit-frame-pointer $< -o $(basename $@)
	@../valgrind-3.11.0/inst/bin/valgrind --tool=memcheck --source-filename=$< --trace-filename=$(basename $<).vgtrace ./$(basename $<) || true

#%.trace: %.vgtrace ../vg_to_opt_trace.py
#	@python ../vg_to_opt_trace.py --create_jsvar=trace $(basename $<) > $(b#asename $<).trace || true

clean:
	rm -f *.trace *.vgtrace *.out
