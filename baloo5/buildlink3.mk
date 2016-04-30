# $NetBSD$

BUILDLINK_TREE+=	baloo5

.if !defined(BALOO5_BUILDLINK3_MK)
BALOO5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo5+=	baloo5>=5.21.0
BUILDLINK_PKGSRCDIR.baloo5?=	../../wip/baloo5

#.include "../../devel/libinotify/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../wip/kfilemetadata5/buildlink3.mk"
.include "../../wip/kidletime/buildlink3.mk"
.include "../../wip/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# BALOO5_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo5
