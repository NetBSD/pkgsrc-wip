# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stringable

.if !defined(HS_STRINGABLE_BUILDLINK3_MK)
HS_STRINGABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringable+=	hs-stringable>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-stringable+=	hs-stringable>=0.1.2
BUILDLINK_PKGSRCDIR.hs-stringable?=	../../wip/hs-stringable

.include "../../wip/hs-system-filepath/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_STRINGABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringable
