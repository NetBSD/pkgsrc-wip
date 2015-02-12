# $NetBSD: buildlink3.mk,v 1.1 2015/02/12 08:02:01 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-pa_bench

.if !defined(OCAML_PA_BENCH_BUILDLINK3_MK)
OCAML_PA_BENCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-pa_bench+=	ocaml-pa_bench>=109.55.02
BUILDLINK_PKGSRCDIR.ocaml-pa_bench?=	../../wip/ocaml-pa_bench
.endif	# OCAML_PA_BENCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-pa_bench
