# $NetBSD: buildlink3.mk,v 1.4 2006/04/06 07:17:12 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ECORE_BUILDLINK3_MK:=	${ECORE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ecore
.endif

BUILDLINK_PACKAGES+=	ecore

.if !empty(ECORE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ecore+=	ecore>=1.0.0nb1
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore
.endif	# ECORE_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
