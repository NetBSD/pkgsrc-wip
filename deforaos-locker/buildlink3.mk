# $NetBSD: buildlink3.mk,v 1.1 2011/12/14 23:43:03 khorben Exp $

BUILDLINK_TREE+=	deforaos-locker

.if !defined(DEFORAOS_LOCKER_BUILDLINK3_MK)
DEFORAOS_LOCKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-locker+=	deforaos-locker>=0.1.1
BUILDLINK_PKGSRCDIR.deforaos-locker?=	../../wip/deforaos-locker

.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_LOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-locker
