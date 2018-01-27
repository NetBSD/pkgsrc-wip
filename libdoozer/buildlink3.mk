# $NetBSD: buildlink3.mk,v 1.1 2013/02/08 20:45:28 tonnerre Exp $

BUILDLINK_TREE+=	libdoozer

.if !defined(LIBDOOZER_BUILDLINK3_MK)
LIBDOOZER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdoozer+=	libdoozer>=0.1
BUILDLINK_PKGSRCDIR.libdoozer?=		../../wip/libdoozer
.endif	# LIBDOOZER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdoozer
