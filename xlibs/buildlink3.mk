# $NetBSD: buildlink3.mk,v 1.2 2004/02/10 18:49:42 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use xlibs.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XLIBS_BUILDLINK3_MK:=	${XLIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xlibs
.endif

.if !empty(XLIBS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xlibs
BUILDLINK_DEPENDS.xlibs+=		xlibs>=1.0
BUILDLINK_PKGSRCDIR.xlibs?=		../../wip/xlibs

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

.endif # XLIBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
