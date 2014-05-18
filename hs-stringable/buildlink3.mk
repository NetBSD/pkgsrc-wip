# $NetBSD: buildlink3.mk,v 1.2 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stringable

.if !defined(HS_STRINGABLE_BUILDLINK3_MK)
HS_STRINGABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringable+=	hs-stringable>=0.1.2
BUILDLINK_PKGSRCDIR.hs-stringable?=	../../wip/hs-stringable

.include "../../wip/hs-system-filepath/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_STRINGABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringable
