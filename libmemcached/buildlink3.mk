# $NetBSD: buildlink3.mk,v 1.2 2010/09/17 11:57:05 fhajny Exp $

BUILDLINK_TREE+=	libmemcached

.if !defined(LIBMEMCACHED_BUILDLINK3_MK)
LIBMEMCACHED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemcached+=	libmemcached>=0.33
BUILDLINK_PKGSRCDIR.libmemcached?=	../../wip/libmemcached
BUILDLINK_FILES.libmemcached=		include/libmemcached/*.h
BUILDLINK_FILES.libmemcached+=		lib/libmemcached.*

.endif	# LIBMEMCACHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemcached
