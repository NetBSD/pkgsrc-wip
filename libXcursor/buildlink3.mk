# $NetBSD: buildlink3.mk,v 1.2 2004/09/30 12:32:06 thomasklausner Exp $
#
# This Makefile fragment is included by packages that use libXcursor.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXCURSOR_BUILDLINK3_MK:=	${LIBXCURSOR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXcursor
.endif

.if !empty(LIBXCURSOR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libXcursor
BUILDLINK_DEPENDS.libXcursor+=		libXcursor>=1.1.1
BUILDLINK_PKGSRCDIR.libXcursor?=		../../wip/libXcursor

.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"

.endif # LIBXCURSOR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
