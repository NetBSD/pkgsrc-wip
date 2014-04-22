# $NetBSD: buildlink3.mk,v 1.3 2014/04/22 19:52:08 outpaddling Exp $

BUILDLINK_TREE+=	munge

.if !defined(MUNGE_BUILDLINK3_MK)
MUNGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.munge+=	munge>=0.5.10
BUILDLINK_PKGSRCDIR.munge?=	../../security/munge

.endif	# MUNGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-munge
