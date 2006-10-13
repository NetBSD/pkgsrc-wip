# $NetBSD: buildlink3.mk,v 1.6 2006/10/13 16:50:51 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXrender.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRENDER_BUILDLINK3_MK:=	${LIBXRENDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXrender
.endif

.if !empty(LIBXRENDER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXrender
BUILDLINK_API_DEPENDS.libXrender+=		libXrender>=0.9.0
BUILDLINK_PKGSRCDIR.libXrender?=		../../wip/libXrender

.include "../../mk/bsd.prefs.mk"
.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.endif

.include "../../x11/renderproto/buildlink3.mk"

.endif # LIBXRENDER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
