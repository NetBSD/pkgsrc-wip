# $NetBSD: buildlink3.mk,v 1.5 2004/06/13 15:04:40 minskim Exp $
#
# This Makefile fragment is included by packages that use libXmu.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXMU_BUILDLINK3_MK:=	${LIBXMU_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXmu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXmu}
BUILDLINK_PACKAGES+=	libXmu

.if !empty(LIBXMU_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libXmu+=		libXmu>=6.2.1nb2
BUILDLINK_PKGSRCDIR.libXmu?=		../../wip/libXmu
.endif # LIBXMU_BUILDLINK3_MK

.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

# libXmu uses libXext's XShapeCombineMask()
LDFLAGS+=	-lXext

.include "../../mk/pthread.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.pthread}
LDFLAGS+=	${BUILDLINK_LDADD.pthread}

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
