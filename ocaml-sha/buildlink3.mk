# $NetBSD$

BUILDLINK_TREE+=	ocaml-sha

.if !defined(OCAML_SHA_BUILDLINK3_MK)
OCAML_SHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sha+=	ocaml-sha>=1.12
BUILDLINK_PKGSRCDIR.ocaml-sha?=		../../wip/ocaml-sha
.endif	# OCAML_SHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sha
