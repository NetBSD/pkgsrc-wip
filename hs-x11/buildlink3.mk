# $NetBSD: buildlink3.mk,v 1.10 2013/02/26 12:51:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-x11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.6.1.1
BUILDLINK_PKGSRCDIR.hs-x11?=	../../wip/hs-x11

.include "../../wip/hs-data-default/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11
