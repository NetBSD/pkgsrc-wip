# $NetBSD: buildlink3.mk,v 1.3 2009/03/27 10:57:56 thomasklausner Exp $

BUILDLINK_TREE+=	p2kmoto

.if !defined(P2KMOTO_BUILDLINK3_MK)
P2KMOTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p2kmoto+=	p2kmoto>=0.1rc1
BUILDLINK_PKGSRCDIR.p2kmoto?=	../../wip/p2kmoto

.include "../../mk/libusb.buildlink3.mk"
.endif # P2KMOTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-p2kmoto
