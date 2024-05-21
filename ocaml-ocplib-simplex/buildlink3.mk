# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:34:37 wiz Exp $

BUILDLINK_TREE+=	ocaml-ocplib-simplex

.if !defined(OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK)
OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ocplib-simplex+=	ocaml-ocplib-simplex>=0.5
BUILDLINK_ABI_DEPENDS.ocaml-ocplib-simplex+=	ocaml-ocplib-simplex>=0.5.1
BUILDLINK_PKGSRCDIR.ocaml-ocplib-simplex?=	../../wip/ocaml-ocplib-simplex

.endif	# OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ocplib-simplex
