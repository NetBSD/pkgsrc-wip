# $NetBSD: buildlink3.mk,v 1.1 2014/02/03 09:41:37 othyro Exp $

BUILDLINK_TREE+=	libcthreads

.if !defined(LIBCTHREADS_BUILDLINK3_MK)
LIBCTHREADS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcthreads+=	libcthreads>=20140105
BUILDLINK_PKGSRCDIR.libcthreads?=	../../wip/libcthreads

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCTHREADS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcthreads
