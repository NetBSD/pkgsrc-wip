# $NetBSD: buildlink3.mk,v 1.2 2014/11/25 09:30:36 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-ounit

.if !defined(OCAML_OUNIT_BUILDLINK3_MK)
OCAML_OUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ounit+=	ocaml-ounit>=2.0.0
BUILDLINK_PKGSRCDIR.ocaml-ounit?=	../../wip/ocaml-ounit
.endif	# OCAML_OUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ounit
