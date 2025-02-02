# $NetBSD: buildlink3.mk,v 1.6 2023/10/21 17:09:53 gdt Exp $

BUILDLINK_TREE+=	libks

.if !defined(LIBKS_BUILDLINK3_MK)
LIBKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libks+=	libks>=2.0.6
BUILDLINK_PKGSRCDIR.libks?=	../../wip/libks

.endif	# LIBKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libks
