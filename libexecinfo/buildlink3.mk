# $NetBSD: buildlink3.mk,v 1.1 2012/02/20 16:12:24 bartoszkuzma Exp $

BUILDLINK_TREE+=	libexecinfo

.if !defined(LIBEXECINFO_BUILDLINK3_MK)
LIBEXECINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexecinfo+=	libexecinfo>=1.1
BUILDLINK_ABI_DEPENDS.libexecinfo+=	libexecinfo>=1.1
BUILDLINK_PKGSRCDIR.libexecinfo?=	../../wip/libexecinfo
.endif	# LIBEXECINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexecinfo
