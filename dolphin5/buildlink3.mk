# $NetBSD$

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_PKGSRCDIR.dolphin?=	../../wip/dolphin5

#.include "../../wip/baloo-widgets/buildlink3.mk"
#.include "../../x11/kactivities5/buildlink3.mk"
#.include "../../devel/kcmutils/buildlink3.mk"
#.include "../../net/knewstuff/buildlink3.mk"
#.include "../../devel/kparts/buildlink3.mk"
#.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
