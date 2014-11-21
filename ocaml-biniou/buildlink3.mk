# $NetBSD: buildlink3.mk,v 1.1 2014/11/21 06:01:35 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-biniou

.if !defined(OCAML_BINIOU_BUILDLINK3_MK)
OCAML_BINIOU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.0.9
BUILDLINK_PKGSRCDIR.ocaml-biniou?=	../../wip/ocaml-biniou
.endif	# OCAML_BINIOU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-biniou
