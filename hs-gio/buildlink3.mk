# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 13:00:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-gio

.if !defined(HS_GIO_BUILDLINK3_MK)
HS_GIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gio+=	hs-gio>=0.12
BUILDLINK_PKGSRCDIR.hs-gio?=	../../wip/hs-gio

.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_GIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gio
