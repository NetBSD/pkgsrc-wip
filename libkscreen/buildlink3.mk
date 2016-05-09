# $NetBSD$

BUILDLINK_TREE+=	libkscreen

.if !defined(LIBKSCREEN_BUILDLINK3_MK)
LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkscreen+=	libkscreen>=5.6.3
BUILDLINK_PKGSRCDIR.libkscreen?=	../../wip/libkscreen

.include "../../wip/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkscreen
