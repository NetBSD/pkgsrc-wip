# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 15:40:56 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXt.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXT_BUILDLINK3_MK:=	${LIBXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXt}
BUILDLINK_PACKAGES+=	libXt

.if !empty(LIBXT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libXt+=		libXt>=0.1.4
BUILDLINK_PKGSRCDIR.libXt?=		../../wip/libXt
.endif # LIBXT_BUILDLINK3_MK

.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xextensions/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.pthread}

# libXt needs IceProcessMessages and SmcSaveYourselfDone and others
LDFLAGS+=	-lICE -lSM

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
