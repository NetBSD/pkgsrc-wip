# $NetBSD$

BUILDLINK_TREE+=	ocaml-sedlex

.if !defined(OCAML_SEDLEX_BUILDLINK3_MK)
OCAML_SEDLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sedlex+=	ocaml-sedlex>=2.1
BUILDLINK_PKGSRCDIR.ocaml-sedlex?=	../../devel/ocaml-sedlex

.endif	# OCAML_SEDLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sedlex
