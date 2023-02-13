# $NetBSD: buildlink3.mk,v 1.1 2020/11/05 16:31:45 bacon Exp $

BUILDLINK_TREE+=	libflame_pthread

.if !defined(LIBFLAME_PTHREAD_BUILDLINK3_MK)
LIBFLAME_PTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libflame_pthread+=	libflame_pthread>=5.2.0
BUILDLINK_PKGSRCDIR.libflame_pthread?=		../../wip/libflame_pthread
.include "../../wip/blis_pthread/buildlink3.mk"
.endif	# LIBFLAME_PTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libflame_pthread
