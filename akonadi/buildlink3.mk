# $NetBSD: buildlink3.mk,v 1.1 2008/07/26 22:23:50 mwdavies Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AKONADI_BUILDLINK3_MK:=	${AKONADI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	akonadi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nakonadi}
BUILDLINK_PACKAGES+=	akonadi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}akonadi

.if ${AKONADI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=0.82.0
BUILDLINK_PKGSRCDIR.akonadi?=	../../wip/akonadi
.endif	# AKONADI_BUILDLINK3_MK

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
