# $NetBSD: buildlink3.mk,v 1.2 2004/10/15 14:53:18 tvierling Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ECORE_BUILDLINK3_MK:=	${ECORE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ecore
.endif

BUILDLINK_PACKAGES+=	ecore

.if !empty(ECORE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ecore+=	ecore>=1.0.0nb1
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore
.endif	# ECORE_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
