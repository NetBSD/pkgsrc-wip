# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-double-conversion

.if !defined(HS_DOUBLE_CONVERSION_BUILDLINK3_MK)
HS_DOUBLE_CONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-double-conversion+=	hs-double-conversion>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-double-conversion+=	hs-double-conversion>=0.2.0.6
BUILDLINK_PKGSRCDIR.hs-double-conversion?=	../../wip/hs-double-conversion

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_DOUBLE_CONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-double-conversion
