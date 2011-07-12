# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 08:10:28 phonohawk Exp $

BUILDLINK_TREE+=	hs-rosezipper

.if !defined(HS_ROSEZIPPER_BUILDLINK3_MK)
HS_ROSEZIPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rosezipper+=	hs-rosezipper>=0.2
BUILDLINK_PKGSRCDIR.hs-rosezipper?=	../../wip/hs-rosezipper
.endif	# HS_ROSEZIPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rosezipper
