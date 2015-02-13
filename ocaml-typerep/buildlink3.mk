# $NetBSD: buildlink3.mk,v 1.1 2015/02/13 05:28:28 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-typerep

.if !defined(OCAML_TYPEREP_BUILDLINK3_MK)
OCAML_TYPEREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-typerep+=	ocaml-typerep>=111.17.00
BUILDLINK_PKGSRCDIR.ocaml-typerep?=	../../wip/ocaml-typerep
.endif	# OCAML_TYPEREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-typerep
