# $NetBSD: buildlink3.mk,v 1.11 2006/04/18 18:27:50 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libX11.

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBX11_BUILDLINK3_MK:=	${LIBX11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libX11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibX11}
BUILDLINK_PACKAGES+=	libX11

.if !empty(LIBX11_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libX11+=		libX11>=0.99.0
BUILDLINK_PKGSRCDIR.libX11?=		../../wip/libX11
.endif # LIBX11_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.pthread}

# as listed in x11.pc pkgconfig file
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/inputproto/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXdmcp/buildlink3.mk"

#.include "../../wip/xtrans/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
