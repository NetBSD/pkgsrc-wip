# $NetBSD: buildlink3.mk,v 1.1 2013/02/23 15:15:19 phonohawk Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=0.1
BUILDLINK_PKGSRCDIR.hs-nats?=	../../wip/hs-nats
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
