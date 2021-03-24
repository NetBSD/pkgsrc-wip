# $NetBSD$

BUILDLINK_TREE+=	kdepim-runtime

.if !defined(KDEPIM_RUNTIME_BUILDLINK3_MK)
KDEPIM_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim-runtime+=	kdepim-runtime>=20.04.1
BUILDLINK_PKGSRCDIR.kdepim-runtime?=	../../wip/kdepim-runtime

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../wip/akonadi-calendar/buildlink3.mk"
.include "../../wip/akonadi-notes/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDEPIM_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim-runtime
