# $NetBSD: buildlink3.mk,v 1.4 2013/10/25 23:29:17 szptvlfn Exp $

BUILDLINK_TREE+=	hs-syb

.if !defined(HS_SYB_BUILDLINK3_MK)
HS_SYB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-syb+=	hs-syb>=0.4.1
BUILDLINK_PKGSRCDIR.hs-syb?=	../../wip/hs-syb
.endif	# HS_SYB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-syb
