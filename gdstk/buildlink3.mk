# $NetBSD$

BUILDLINK_TREE+=	gdstk

.if !defined(GDSTK_BUILDLINK3_MK)
GDSTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdstk+=	gdstk>=0.9.58
BUILDLINK_PKGSRCDIR.gdstk?=	../../wip/gdstk

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.endif	# GDSTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdstk
