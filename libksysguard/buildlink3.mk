# $NetBSD$

BUILDLINK_TREE+=	libksysguard

.if !defined(LIBKSYSGUARD_BUILDLINK3_MK)
LIBKSYSGUARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksysguard+=	libksysguard>=5.6.3
BUILDLINK_ABI_DEPENDS.libksysguard?=	libksysguard>=5.18.5nb1
BUILDLINK_PKGSRCDIR.libksysguard?=	../../wip/libksysguard

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif	# LIBKSYSGUARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksysguard
