# $NetBSD: buildlink3.mk,v 1.3 2004/08/17 21:26:45 thomasklausner Exp $
#
# This Makefile fragment is included by packages that use compositeext.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COMPOSITEEXT_BUILDLINK3_MK:=	${COMPOSITEEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	compositeext
.endif

.if !empty(COMPOSITEEXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			compositeext
BUILDLINK_DEPENDS.compositeext?=		compositeext>=2.0
BUILDLINK_PKGSRCDIR.compositeext?=		../../wip/compositeext

.include "../../x11/fixesext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"

.endif # COMPOSITEEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
