# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/11/10 01:49:53 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.xf86vidmodeproto?=	build

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XF86VIDMODEPROTO_BUILDLINK3_MK:=	${XF86VIDMODEPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xf86vidmodeproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxf86vidmodeproto}
BUILDLINK_PACKAGES+=	xf86vidmodeproto

.if !empty(XF86VIDMODEPROTO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xf86vidmodeproto+=	xf86vidmodeproto>=2.2.1
BUILDLINK_PKGSRCDIR.xf86vidmodeproto?=	../../new/xf86vidmodeproto
.endif	# XF86VIDMODEPROTO_BUILDLINK3_MK

.include "../../wip/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
