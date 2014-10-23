# $NetBSD: buildlink3.mk,v 1.1 2014/10/23 07:43:40 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-camomile

.if !defined(OCAML_CAMOMILE_BUILDLINK3_MK)
OCAML_CAMOMILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-camomile+=	ocaml-camomile>=0.8.4
BUILDLINK_PKGSRCDIR.ocaml-camomile?=	../../wip/ocaml-camomile

.include "../../lang/ocaml/buildlink3.mk"

.endif	# OCAML_CAMOMILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-camomile
