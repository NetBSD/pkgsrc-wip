# $NetBSD: buildlink3.mk,v 1.3 2012/01/22 13:21:47 airhead Exp $

BUILDLINK_TREE+=	stfl

.if !defined(STFL_BUILDLINK3_MK)
STFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stfl+=	stfl>=0.19
BUILDLINK_PKGSRCDIR.stfl?=	../../wip/stfl
.endif	# STFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-stfl
