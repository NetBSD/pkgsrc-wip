# $NetBSD: buildlink3.mk,v 1.4 2008/11/04 10:14:30 mwdavies Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
KDEBASE_WORKSPACE_BUILDLINK3_MK:=	${KDEBASE_WORKSPACE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdebase-workspace
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebase-workspace}
BUILDLINK_PACKAGES+=	kdebase-workspace
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdebase-workspace

.if ${KDEBASE_WORKSPACE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdebase-workspace+=	kdebase-workspace4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-workspace?=	kdebase-workspace4>=4.0.0nb1
BUILDLINK_PKGSRCDIR.kdebase-workspace?=	../../wip/kdebase-workspace4
.endif	# KDEBASE_WORKSPACE_BUILDLINK3_MK

.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
