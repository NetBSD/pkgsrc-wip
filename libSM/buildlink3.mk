# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 07:17:31 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libSM.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSM_BUILDLINK3_MK:=	${LIBSM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libSM
.endif

.if !empty(LIBSM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libSM
BUILDLINK_API_DEPENDS.libSM+=		libSM>=0.99.2
BUILDLINK_PKGSRCDIR.libSM?=		../../wip/libSM

.endif # LIBSM_BUILDLINK3_MK

.include "../../wip/libICE/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
