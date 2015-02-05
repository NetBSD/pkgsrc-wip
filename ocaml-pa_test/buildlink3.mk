# $NetBSD: buildlink3.mk,v 1.1 2015/02/05 01:39:42 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-pa_test

.if !defined(OCAML_PA_TEST_BUILDLINK3_MK)
OCAML_PA_TEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-pa_test+=	ocaml-pa_test>=111.08.00
BUILDLINK_PKGSRCDIR.ocaml-pa_test?=	../../wip/ocaml-pa_test
.endif	# OCAML_PA_TEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-pa_test
