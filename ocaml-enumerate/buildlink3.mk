# $NetBSD: buildlink3.mk,v 1.1 2014/11/16 22:51:00 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-enumerate

.if !defined(OCAML_ENUMERATE_BUILDLINK3_MK)
OCAML_ENUMERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-enumerate+=	ocaml-enumerate>=111.08.00
BUILDLINK_PKGSRCDIR.ocaml-enumerate?=	../../wip/ocaml-enumerate

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.endif	# OCAML_ENUMERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-enumerate
