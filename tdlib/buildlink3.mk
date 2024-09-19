# $NetBSD$

BUILDLINK_TREE+=	tdlib

.if !defined(TDLIB_BUILDLINK3_MK)
TDLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdlib+=	tdlib>=1.6.0
BUILDLINK_PKGSRCDIR.tdlib?=	../../wip/tdlib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif	# TDLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdlib
