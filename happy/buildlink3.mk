# $NetBSD: buildlink3.mk,v 1.10 2014/05/16 20:47:07 szptvlfn Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy+=	happy>=1.19.2
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy

.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
