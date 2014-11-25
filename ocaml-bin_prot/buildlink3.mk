# $NetBSD: buildlink3.mk,v 1.2 2014/11/25 07:51:13 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-bin_prot

.if !defined(OCAML_BIN_PROT_BUILDLINK3_MK)
OCAML_BIN_PROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bin_prot+=	ocaml-bin_prot>=112.01.00
BUILDLINK_PKGSRCDIR.ocaml-bin_prot?=	../../wip/ocaml-bin_prot
.endif	# OCAML_BIN_PROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bin_prot
