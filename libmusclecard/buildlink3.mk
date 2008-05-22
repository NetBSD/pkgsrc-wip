# $NetBSD: buildlink3.mk,v 1.3 2008/05/22 16:02:39 tnn2 Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMUSCLECARD_BUILDLINK3_MK:=	${LIBMUSCLECARD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmusclecard
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmusclecard}
BUILDLINK_PACKAGES+=	libmusclecard

.if !empty(LIBMUSCLECARD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libmusclecard+=	libmusclecard>=1.2.9
BUILDLINK_PKGSRCDIR.libmusclecard?=	../../wip/libmusclecard
.endif	# LIBMUSCLECARD_BUILDLINK3_MK

.include "../../security/pcsc-lite/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
