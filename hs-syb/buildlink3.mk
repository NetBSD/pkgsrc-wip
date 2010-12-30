# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/30 07:24:04 phonohawk Exp $

BUILDLINK_TREE+=	hs-syb

.if !defined(HS_SYB_BUILDLINK3_MK)
HS_SYB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-syb+=	hs-syb>=0.3
BUILDLINK_PKGSRCDIR.hs-syb?=	../../wip/hs-syb
.endif	# HS_SYB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-syb
