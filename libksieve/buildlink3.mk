# $NetBSD$

BUILDLINK_TREE+=	libksieve

.if !defined(LIBKSIEVE_BUILDLINK3_MK)
LIBKSIEVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksieve+=	libksieve>=20.04.1
BUILDLINK_PKGSRCDIR.libksieve?=		../../wip/libksieve

.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKSIEVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksieve
