# $NetBSD$

BUILDLINK_TREE+=	kdelibs

.if !defined(KDELIBS_BUILDLINK3_MK)
KDELIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdelibs+=        kdelibs1>=0
BUILDLINK_ABI_DEPENDS.kdelibs+=        kdelibs1>=0
BUILDLINK_PKGSRCDIR.kdelibs?=          ../../wip/kdelibs1

.include "../../wip/qt1/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-kdelibs
