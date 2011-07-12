# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 15:55:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-rosezipper1

.if !defined(HS_ROSEZIPPER1_BUILDLINK3_MK)
HS_ROSEZIPPER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rosezipper1+=	hs-rosezipper1>=0.1
BUILDLINK_PKGSRCDIR.hs-rosezipper1?=	../../wip/hs-rosezipper1
.endif	# HS_ROSEZIPPER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rosezipper1
