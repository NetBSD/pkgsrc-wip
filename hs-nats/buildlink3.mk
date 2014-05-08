# $NetBSD: buildlink3.mk,v 1.3 2014/05/08 00:39:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=0.1.3
BUILDLINK_PKGSRCDIR.hs-nats?=	../../wip/hs-nats
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
