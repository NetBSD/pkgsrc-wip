# $NetBSD: buildlink3.mk,v 1.3 2011/01/14 07:01:50 phonohawk Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.happy?=	build
BUILDLINK_API_DEPENDS.happy+=	happy>=1.18
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy
.endif # HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
