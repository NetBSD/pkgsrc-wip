# $NetBSD$

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=20.04.1
BUILDLINK_PKGSRCDIR.libkgapi?=	../../wip/libkgapi

.include "../../devel/kio/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../wip/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
