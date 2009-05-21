# $NetBSD: buildlink3.mk,v 1.3 2009/05/21 04:56:42 phonohawk Exp $

BUILDLINK_TREE+=	hs-zlib

.if !defined(HS_ZLIB_BUILDLINK3_MK)
HS_ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zlib+=	hs-zlib>=0.5.0.0nb1
BUILDLINK_PKGSRCDIR.hs-zlib?=	../../wip/hs-zlib

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zlib
