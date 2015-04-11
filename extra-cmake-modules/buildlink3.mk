# $NetBSD: buildlink3.mk,v 1.1 2015/04/11 12:36:52 krytarowski Exp $

BUILDLINK_TREE+=	extra-cmake-modules

.if !defined(EXTRA_CMAKE_MODULES_BUILDLINK3_MK)
EXTRA_CMAKE_MODULES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=5.9.0
BUILDLINK_PKGSRCDIR.extra-cmake-modules?=	../../wip/extra-cmake-modules

.include "../../x11/qt5-qttools/buildlink3.mk"
.endif	# EXTRA_CMAKE_MODULES_BUILDLINK3_MK

BUILDLINK_TREE+=	-extra-cmake-modules
