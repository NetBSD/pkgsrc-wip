# $NetBSD: buildlink3.mk,v 1.7 2022/08/13 09:38:09 tnn Exp $

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=21.1.0
BUILDLINK_PKGSRCDIR.libcxx?=	../../wip/libcxx

.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
