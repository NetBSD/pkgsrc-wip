# $NetBSD: buildlink3.mk,v 1.1 2013/08/29 02:10:07 outpaddling Exp $

BUILDLINK_TREE+=	munge

.if !defined(MUNGE_BUILDLINK3_MK)
MUNGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.munge+=	munge>=0.5.10
BUILDLINK_PKGSRCDIR.munge?=	../../wip/munge

.endif	# MUNGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-munge
