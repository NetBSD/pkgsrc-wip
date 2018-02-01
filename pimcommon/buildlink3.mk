# $NetBSD$

BUILDLINK_TREE+=	pimcommon

.if !defined(PIMCOMMON_BUILDLINK3_MK)
PIMCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pimcommon+=	pimcommon>=17.12.1
BUILDLINK_PKGSRCDIR.pimcommon?=	../../wip/pimcommon

.include "../../wip/kimap/buildlink3.mk"
.include "../../wip/kpimtextedit/buildlink3.mk"
.include "../../wip/libkdepim/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PIMCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pimcommon
