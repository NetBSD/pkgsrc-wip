# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libpthread-stubs

.if !defined(LIBPTHREAD_STUBS_BUILDLINK3_MK)
LIBPTHREAD_STUBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpthread-stubs+=	libpthread-stubs>=1.0nb4
BUILDLINK_PKGSRCDIR.libpthread-stubs?=	../../wip/libpthread-stubs
.endif # LIBPTHREAD_STUBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpthread-stubs
