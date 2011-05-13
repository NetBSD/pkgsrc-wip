# $NetBSD: buildlink3.mk,v 1.5 2011/05/13 23:25:15 mwdavies Exp $

BUILDLINK_TREE+=	kdegraphics4

.if !defined(KDEGRAPHICS4_BUILDLINK3_MK)
KDEGRAPHICS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics4+=	kdegraphics4>=4.1.1
BUILDLINK_ABI_DEPENDS.kdegraphics4?=	kdegraphics4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kdegraphics4?=	../../graphics/kdegraphics4

.include "../../graphics/tiff/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.endif # KDEGRAPHICS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics4
