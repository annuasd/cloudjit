; ModuleID = 'l.c'
source_filename = "l.c"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx13.0.0"

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define i32 @w(double noundef %i) #0 {
entry:
  %i.addr = alloca double, align 8
  %a = alloca i32, align 4
  store double %i, double* %i.addr, align 8
  store i32 0, i32* %a, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load double, double* %i.addr, align 8
  %cmp = fcmp olt double %0, 3.000000e+00
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %1 = load i32, i32* %a, align 4
  %inc = add nsw i32 %1, 1
  store i32 %inc, i32* %a, align 4
  %2 = load double, double* %i.addr, align 8
  %inc1 = fadd double %2, 1.000000e+00
  store double %inc1, double* %i.addr, align 8
  br label %while.cond, !llvm.loop !10

while.end:                                        ; preds = %while.cond
  %3 = load i32, i32* %a, align 4
  ret i32 %3
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define double @sum(i32 noundef %a, float noundef %b) #0 {
entry:
  %a.addr = alloca i32, align 4
  %b.addr = alloca float, align 4
  store i32 %a, i32* %a.addr, align 4
  store float %b, float* %b.addr, align 4
  %0 = load i32, i32* %a.addr, align 4
  %conv = sitofp i32 %0 to double
  %1 = load float, float* %b.addr, align 4
  %conv1 = fpext float %1 to double
  %add = fadd double %conv, %conv1
  ret double %add
}

attributes #0 = { noinline nounwind optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "min-legal-vector-width"="0" "no-trapping-math"="true" "probe-stack"="__chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+crc,+crypto,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+lse,+neon,+ras,+rcpc,+rdm,+sha2,+sha3,+sm4,+v8.5a,+zcm,+zcz" }

!llvm.module.flags = !{!0, !1, !2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 13, i32 3]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"branch-target-enforcement", i32 0}
!3 = !{i32 8, !"sign-return-address", i32 0}
!4 = !{i32 8, !"sign-return-address-all", i32 0}
!5 = !{i32 8, !"sign-return-address-with-bkey", i32 0}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 1}
!9 = !{!"Apple clang version 14.0.3 (clang-1403.0.22.14.1)"}
!10 = distinct !{!10, !11}
!11 = !{!"llvm.loop.mustprogress"}
