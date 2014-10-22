# $NetBSD: buildlink3.mk,v 1.1 2014/10/22 07:59:07 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-ounit

.if !defined(OCAML_OUNIT_BUILDLINK3_MK)
OCAML_OUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ounit+=	ocaml-ounit>=2.0.0
BUILDLINK_PKGSRCDIR.ocaml-ounit?=	../../wip/ocaml-ounit

.include "../../lang/ocaml/buildlink3.mk"

.endif	# OCAML_OUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ounit
