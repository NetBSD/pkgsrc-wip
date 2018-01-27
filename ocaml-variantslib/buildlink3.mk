# $NetBSD: buildlink3.mk,v 1.1 2015/02/13 05:31:32 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-variantslib

.if !defined(OCAML_VARIANTSLIB_BUILDLINK3_MK)
OCAML_VARIANTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-variantslib+=	ocaml-variantslib>=109.10.00
BUILDLINK_PKGSRCDIR.ocaml-variantslib?=		../../wip/ocaml-variantslib
.endif	# OCAML_VARIANTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-variantslib
