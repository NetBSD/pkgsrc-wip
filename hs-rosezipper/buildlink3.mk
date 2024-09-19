# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-rosezipper

.if !defined(HS_ROSEZIPPER_BUILDLINK3_MK)
HS_ROSEZIPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rosezipper+=	hs-rosezipper>=0.2
BUILDLINK_ABI_DEPENDS.hs-rosezipper+=	hs-rosezipper>=0.2
BUILDLINK_PKGSRCDIR.hs-rosezipper?=	../../wip/hs-rosezipper
.endif	# HS_ROSEZIPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rosezipper
