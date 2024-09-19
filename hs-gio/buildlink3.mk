# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:13 szptvlfn Exp $

BUILDLINK_TREE+=	hs-gio

.if !defined(HS_GIO_BUILDLINK3_MK)
HS_GIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gio+=	hs-gio>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-gio+=	hs-gio>=0.12.3
BUILDLINK_PKGSRCDIR.hs-gio?=	../../wip/hs-gio

.include "../../wip/hs-glib/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_GIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gio
