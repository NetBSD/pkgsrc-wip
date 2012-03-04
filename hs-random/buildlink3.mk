# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/04 08:29:44 phonohawk Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.0.1
BUILDLINK_PKGSRCDIR.hs-random?=	../../wip/hs-random
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
