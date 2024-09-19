# $NetBSD: buildlink3.mk,v 1.2 2014/11/25 09:23:53 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-fieldslib

.if !defined(OCAML_FIELDSLIB_BUILDLINK3_MK)
OCAML_FIELDSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fieldslib+=	ocaml-fieldslib>=109.19.00
BUILDLINK_PKGSRCDIR.ocaml-fieldslib?=	../../wip/ocaml-fieldslib
.endif	# OCAML_FIELDSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fieldslib
