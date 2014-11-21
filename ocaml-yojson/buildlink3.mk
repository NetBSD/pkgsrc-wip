# $NetBSD: buildlink3.mk,v 1.1 2014/11/21 06:24:55 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-yojson

.if !defined(OCAML_YOJSON_BUILDLINK3_MK)
OCAML_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.1.8
BUILDLINK_PKGSRCDIR.ocaml-yojson?=	../../wip/ocaml-yojson
.endif	# OCAML_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yojson
