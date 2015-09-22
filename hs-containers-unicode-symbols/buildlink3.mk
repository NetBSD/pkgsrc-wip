# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-containers-unicode-symbols

.if !defined(HS_CONTAINERS_UNICODE_SYMBOLS_BUILDLINK3_MK)
HS_CONTAINERS_UNICODE_SYMBOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-containers-unicode-symbols+=	hs-containers-unicode-symbols>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-containers-unicode-symbols+=	hs-containers-unicode-symbols>=0.3.0.2
BUILDLINK_PKGSRCDIR.hs-containers-unicode-symbols?=	../../wip/hs-containers-unicode-symbols

.include "../../devel/hs-base-unicode-symbols/buildlink3.mk"
.endif	# HS_CONTAINERS_UNICODE_SYMBOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-containers-unicode-symbols
