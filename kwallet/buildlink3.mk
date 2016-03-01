# $NetBSD$

BUILDLINK_TREE+=	kwallet

.if !defined(KWALLET_BUILDLINK3_MK)
KWALLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwallet+=	kwallet>=5.19.0
BUILDLINK_PKGSRCDIR.kwallet?=	../../wip/kwallet

.include "../../wip/gpgmepp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/kiconthemes/buildlink3.mk"
.include "../../wip/knotifications/buildlink3.mk"
.include "../../wip/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWALLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwallet
