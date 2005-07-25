# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/25 21:28:57 udontknow Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSCLE_PKCS11_BUILDLINK3_MK:=	${MUSCLE_PKCS11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	muscle-pkcs11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmuscle-pkcs11}
BUILDLINK_PACKAGES+=	muscle-pkcs11

.if !empty(MUSCLE_PKCS11_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.muscle-pkcs11+=	muscle-pkcs11>=1.1.5
BUILDLINK_PKGSRCDIR.muscle-pkcs11?=	../../wip/muscle-pkcs11
.endif	# MUSCLE_PKCS11_BUILDLINK3_MK

.include "../../wip/libmusclecard/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
