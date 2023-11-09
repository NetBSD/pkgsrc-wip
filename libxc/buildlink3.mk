# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/05 21:06:58 jihbed Exp $

BUILDLINK_TREE+=	libxc

.if !defined(LIBXC_BUILDLINK3_MK)
LIBXC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxc+=	libxc>=6.2.2
BUILDLINK_PKGSRCDIR.libxc?=	../../wip/libxc
.endif	# LIBXC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxc
