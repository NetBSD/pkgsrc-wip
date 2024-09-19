# $NetBSD$
BUILDLINK_TREE+=	ocaml-gen

.if !defined(OCAML_GEN_BUILDLINK3_MK)
OCAML_GEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-gen+=	ocaml-gen>=0.5.1
BUILDLINK_PKGSRCDIR.ocaml-gen?=		../../wip/ocaml-gen

.endif	# OCAML_GEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-gen
