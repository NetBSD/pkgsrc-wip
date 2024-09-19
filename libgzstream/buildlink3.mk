# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/08/25 18:20:52 jihbed Exp $

BUILDLINK_TREE+=	libgzstream

.if !defined(LIBGZSTREAM_BUILDLINK3_MK)
LIBGZSTREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgzstream+=	libgzstream>=1.5
BUILDLINK_PKGSRCDIR.libgzstream?=	../../wip/libgzstream

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBGZSTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgzstream
