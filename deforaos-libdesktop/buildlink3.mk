# $NetBSD: buildlink3.mk,v 1.1 2009/12/30 22:25:54 khorben Exp $

BUILDLINK_TREE+=	deforaos-libdesktop

.if !defined(DEFORAOS_LIBDESKTOP_BUILDLINK3_MK)
DEFORAOS_LIBDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdesktop+=	deforaos-libdesktop>=0.0.1
BUILDLINK_PKGSRCDIR.deforaos-libdesktop?=	../../wip/deforaos-libdesktop

.endif	# DEFORAOS_LIBDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdesktop
