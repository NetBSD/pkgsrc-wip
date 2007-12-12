# $NetBSD: buildlink3.mk,v 1.1 2007/12/12 10:21:02 mwdavies Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
KDEBASE_WORKSPACE_BUILDLINK3_MK:=	${KDEBASE_WORKSPACE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdebase-workspace
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebase-workspace}
BUILDLINK_PACKAGES+=	kdebase-workspace
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdebase-workspace

.if ${KDEBASE_WORKSPACE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdebase-workspace+=	kdebase-workspace>=3.97.0
BUILDLINK_PKGSRCDIR.kdebase-workspace?=	../../wip/kdebase-workspace4
.endif	# KDEBASE_WORKSPACE_BUILDLINK3_MK

.include "../../wip/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../x11/libxklavier/buildlink3.mk"
#.include "../../x11/libXcomposite/buildlink3.mk"
#.include "../../x11/libXdamage/buildlink3.mk"
#.include "../../x11/libXres/buildlink3.mk"
#.include "../../x11/libXScrnSaver/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
