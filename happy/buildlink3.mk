# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.happy?=	build
BUILDLINK_API_DEPENDS.happy+=	happy>=1.18.2
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy
.endif # HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
