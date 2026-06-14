# $NetBSD$

BUILDLINK_TREE+=	knot

.if !defined(KNOT_BUILDLINK3_MK)
KNOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knot+=	knot>=3.5.5
BUILDLINK_PKGSRCDIR.knot?=	../../net/knot

.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"

BUILDLINK_TREE+=	-knot
