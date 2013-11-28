# $NetBSD: buildlink3.mk,v 1.9 2013/11/28 13:23:46 szptvlfn Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy+=	happy>=1.19.2
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
