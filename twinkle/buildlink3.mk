# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	twinkle

.if !defined(TWINKLE_BUILDLINK3_MK)
TWINKLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twinkle+=	twinkle>=1.1
BUILDLINK_PKGSRCDIR.twinkle?=	../../wip/twinkle

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.endif # TWINKLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-twinkle
