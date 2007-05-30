# $NetBSD: buildlink3.mk,v 1.4 2007/05/30 17:41:49 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBINSTALLER_BUILDLINK3_MK:=	${LIBINSTALLER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libinstaller
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibinstaller}
BUILDLINK_PACKAGES+=	libinstaller
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libinstaller

.if ${LIBINSTALLER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libinstaller+=	libinstaller>=5.1
BUILDLINK_PKGSRCDIR.libinstaller?=	../../wip/libinstaller
.endif	# LIBINSTALLER_BUILDLINK3_MK

.include "../../wip/libdfui/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
