# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 15:40:57 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use xlibs.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XLIBS_BUILDLINK3_MK:=	${XLIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xlibs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxlibs}
BUILDLINK_PACKAGES+=	xlibs

.if !empty(XLIBS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xlibs+=		xlibs>=1.0
BUILDLINK_PKGSRCDIR.xlibs?=		../../wip/xlibs
.endif # XLIBS_BUILDLINK3_MK

.include "../../wip/xextensions/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXmu/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXi/buildlink3.mk"
.include "../../wip/libXv/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libXres/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
