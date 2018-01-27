# $NetBSD: buildlink3.mk,v 1.1 2014/11/17 11:46:14 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-easy-format

.if !defined(OCAML_EASY_FORMAT_BUILDLINK3_MK)
OCAML_EASY_FORMAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-easy-format+=	ocaml-easy-format>=1.0.2
BUILDLINK_PKGSRCDIR.ocaml-easy-format?=		../../wip/ocaml-easy-format

.endif	# OCAML_EASY_FORMAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-easy-format
