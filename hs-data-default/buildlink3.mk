# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/02 16:38:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.2
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../wip/hs-data-default
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
