# $NetBSD$

BUILDLINK_TREE+=	libpthread-stubs

.if !defined(LIBPTHREAD_STUBS_BUILDLINK3_MK)
LIBPTHREAD_STUBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpthread-stubs+=	libpthread-stubs>=0.3
BUILDLINK_PKGSRCDIR.libpthread-stubs?=		../../wip/libpthread-stubs
.endif	# LIBPTHREAD_STUBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpthread-stubs
