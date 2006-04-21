# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/21 04:21:42 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.trapproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TRAPPROTO_BUILDLINK3_MK:=	${TRAPPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	trapproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntrapproto}
BUILDLINK_PACKAGES+=	trapproto

.if !empty(TRAPPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.trapproto+=	trapproto>=3.4.3
BUILDLINK_PKGSRCDIR.trapproto?=	../../wip/trapproto
.endif	# TRAPPROTO_BUILDLINK3_MK

# Requires: xt.pc from libXt
# headers use X11/Intrinsic.h from libXt

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
