# $NetBSD: buildlink3.mk,v 1.2 2008/01/11 20:52:36 mwdavies Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEBASE_RUNTIME_BUILDLINK3_MK:=	${KDEBASE_RUNTIME_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdebase-runtime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebase-runtime}
BUILDLINK_PACKAGES+=	kdebase-runtime
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdebase-runtime

.if ${KDEBASE_RUNTIME_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdebase-runtime+=	kdebase-runtime4>=4.0.0
BUILDLINK_PKGSRCDIR.kdebase-runtime?=	../../wip/kdebase-runtime4
.endif	# KDEBASE_RUNTIME_BUILDLINK3_MK

.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdepimlibs4/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
