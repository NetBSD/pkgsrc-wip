# $NetBSD: buildlink3.mk,v 1.1 2015/02/12 08:03:34 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-pipebang

.if !defined(OCAML_PIPEBANG_BUILDLINK3_MK)
OCAML_PIPEBANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-pipebang+=	ocaml-pipebang>=110.01.00
BUILDLINK_PKGSRCDIR.ocaml-pipebang?=	../../wip/ocaml-pipebang
.endif	# OCAML_PIPEBANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-pipebang
