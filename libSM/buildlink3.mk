# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 18:19:04 jeremy-c-reed Exp $
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
BUILDLINK_DEPENDS.libSM+=		libSM>=6.0.1
BUILDLINK_PKGSRCDIR.libSM?=		../../wip/libSM

.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

LIBS+=					${BUILDLINK_LDADD.pthread}

.endif # LIBSM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
