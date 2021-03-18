# $NetBSD$

BUILDLINK_TREE+=	kdepim-apps-libs

.if !defined(KDEPIM_APPS_LIBS_BUILDLINK3_MK)
KDEPIM_APPS_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim-apps-libs+=	kdepim-apps-libs>=20.04.1
BUILDLINK_PKGSRCDIR.kdepim-apps-libs?=	../../wip/kdepim-apps-libs

.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../wip/libkleo/buildlink3.mk"
.include "../../wip/grantleetheme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDEPIM_APPS_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim-apps-libs
