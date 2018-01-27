# $NetBSD: buildlink3.mk,v 1.9 2010/12/26 05:01:21 davesainty Exp $

BUILDLINK_TREE+=	DirectFB

.if !defined(DIRECTFB_BUILDLINK3_MK)
DIRECTFB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.DirectFB+=	directfb>=0.9.17
BUILDLINK_ABI_DEPENDS.DirectFB?=	directfb>=0.9.22nb3
BUILDLINK_PKGSRCDIR.DirectFB?=		../../wip/directfb

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif # DIRECTFB_BUILDLINK3_MK

BUILDLINK_TREE+=	-DirectFB
