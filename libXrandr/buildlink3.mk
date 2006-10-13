# $NetBSD: buildlink3.mk,v 1.4 2006/10/13 12:31:37 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXrandr.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRANDR_BUILDLINK3_MK:=	${LIBXRANDR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXrandr
.endif

.if !empty(LIBXRANDR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXrandr
BUILDLINK_API_DEPENDS.libXrandr+=		libXrandr>=0.9.0
BUILDLINK_PKGSRCDIR.libXrandr?=		../../wip/libXrandr

.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.  include "../../wip/libXext/buildlink3.mk"
.endif

.include "../../x11/randrproto/buildlink3.mk"

.endif # LIBXRANDR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
