# $NetBSD: buildlink3.mk,v 1.3 2004/06/09 03:03:34 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FIXESEXT_BUILDLINK3_MK:=	${FIXESEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fixesext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfixesext}
BUILDLINK_PACKAGES+=	fixesext

.if !empty(FIXESEXT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fixesext+=	fixesext>=2.0
BUILDLINK_PKGSRCDIR.fixesext?=	../../wip/fixesext
BUILDLINK_DEPMETHOD.fixesext?=	build
.endif	# FIXESEXT_BUILDLINK3_MK

.include "../../x11/xextensions/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
