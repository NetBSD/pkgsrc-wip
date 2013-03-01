# $NetBSD: buildlink3.mk,v 1.6 2013/03/01 20:47:28 szptvlfn Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy+=	happy>=1.18.10
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy

.endif	# HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
