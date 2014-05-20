# $NetBSD: buildlink3.mk,v 1.12 2014/05/20 21:23:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-x11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.6.1
BUILDLINK_PKGSRCDIR.hs-x11?=	../../wip/hs-x11

.include "../../devel/hs-data-default/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11
