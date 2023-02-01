# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-storable-record

.if !defined(HS_STORABLE_RECORD_BUILDLINK3_MK)
HS_STORABLE_RECORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.1
BUILDLINK_PKGSRCDIR.hs-storable-record?=	../../wip/hs-storable-record

.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLE_RECORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storable-record
