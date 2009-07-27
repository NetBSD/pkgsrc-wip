# $NetBSD: buildlink3.mk,v 1.4 2009/07/27 03:08:33 phonohawk Exp $

BUILDLINK_TREE+=	hs-zlib

.if !defined(HS_ZLIB_BUILDLINK3_MK)
HS_ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zlib+=	hs-zlib>=0.5.2.0
BUILDLINK_PKGSRCDIR.hs-zlib?=	../../wip/hs-zlib

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zlib
