# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 07:16:56 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AOLSERVER4_BUILDLINK3_MK:=	${AOLSERVER4_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aolserver4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naolserver4}
BUILDLINK_PACKAGES+=	aolserver4

.if !empty(AOLSERVER4_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.aolserver4+=		aolserver>=4.0.7
BUILDLINK_PKGSRCDIR.aolserver4?=	../../wip/aolserver4

.endif	# AOLSERVER4_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
