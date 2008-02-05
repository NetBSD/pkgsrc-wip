# $NetBSD: buildlink3.mk,v 1.1 2008/02/05 02:14:19 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENAL_SOFT_BUILDLINK3_MK:=	${OPENAL_SOFT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	openal-soft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenal-soft}
BUILDLINK_PACKAGES+=	openal-soft
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openal-soft

.if ${OPENAL_SOFT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.2.218
#BUILDLINK_PKGSRCDIR.openal-soft?=	../../audio/openal-soft
BUILDLINK_PKGSRCDIR.openal-soft?=	../../wip/openal-soft
.endif	# OPENAL_SOFT_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
