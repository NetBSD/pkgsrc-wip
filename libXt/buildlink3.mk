# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 18:40:12 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXt.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXT_BUILDLINK3_MK:=	${LIBXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXt
.endif

.if !empty(LIBXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXt
BUILDLINK_DEPENDS.libXt+=		libXt>=0.1.4
BUILDLINK_PKGSRCDIR.libXt?=		../../wip/libXt

.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xextensions/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.pthread}

.endif # LIBXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
