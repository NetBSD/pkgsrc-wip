# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/26 20:06:49 udontknow Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MUSCLE_PAM_BUILDLINK3_MK:=	${MUSCLE_PAM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	muscle-pam
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmuscle-pam}
BUILDLINK_PACKAGES+=	muscle-pam

.if !empty(MUSCLE_PAM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.muscle-pam+=	muscle-pam>=1.1.5
BUILDLINK_PKGSRCDIR.muscle-pam?=	../../wip/muscle-pam
.endif	# MUSCLE_PAM_BUILDLINK3_MK

.include "../../wip/libmusclecard/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
