# $NetBSD: buildlink3.mk,v 1.1 2015/04/18 20:05:34 jgoamakf Exp $

BUILDLINK_TREE+=	ocaml-zed

.if !defined(OCAML_ZED_BUILDLINK3_MK)
OCAML_ZED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zed+=	ocaml-zed>=1.2
BUILDLINK_PKGSRCDIR.ocaml-zed?=		../../wip/ocaml-zed

.include "../../wip/ocaml-camomile/buildlink3.mk"
.endif	# OCAML_ZED_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zed
