# $NetBSD: buildlink3.mk,v 1.2 2014/11/25 09:22:23 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-enumerate

.if !defined(OCAML_ENUMERATE_BUILDLINK3_MK)
OCAML_ENUMERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-enumerate+=	ocaml-enumerate>=111.08.00
BUILDLINK_PKGSRCDIR.ocaml-enumerate?=	../../wip/ocaml-enumerate
.endif	# OCAML_ENUMERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-enumerate
