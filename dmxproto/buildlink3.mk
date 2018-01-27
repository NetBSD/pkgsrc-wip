# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	dmxproto

.if !defined(DMXPROTO_BUILDLINK3_MK)
DMXPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dmxproto+=	dmxproto>=2.2.2
BUILDLINK_PKGSRCDIR.dmxproto?=		../../wip/dmxproto

.include "../../x11/xproto/buildlink3.mk"
.endif # DMXPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-dmxproto
