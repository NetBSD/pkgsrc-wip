# $NetBSD: buildlink3.mk,v 1.2 2011/12/01 22:50:49 phonohawk Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.3.0
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../wip/hs-data-default

.include "../../wip/hs-dlist/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
