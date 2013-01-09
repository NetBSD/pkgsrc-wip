# $NetBSD: buildlink3.mk,v 1.5 2013/01/09 23:34:20 szptvlfn Exp $

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy+=	happy>=1.18.9
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy

.endif	# HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
