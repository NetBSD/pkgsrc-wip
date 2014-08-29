# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:22 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hostname

.if !defined(HS_HOSTNAME_BUILDLINK3_MK)
HS_HOSTNAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hostname+=	hs-hostname>=1.0
BUILDLINK_ABI_DEPENDS.hs-hostname+=	hs-hostname>=1.0
BUILDLINK_PKGSRCDIR.hs-hostname?=	../../wip/hs-hostname
.endif	# HS_HOSTNAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hostname
