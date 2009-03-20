# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libzrtpcpp

.if !defined(LIBZRTPCPP_BUILDLINK3_MK)
LIBZRTPCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=0.9.0
BUILDLINK_ABI_DEPENDS.libzrtpcpp?=	libzrtpcpp>=0.9.0nb1
BUILDLINK_PKGSRCDIR.libzrtpcpp?=	../../wip/libzrtpcpp

.include "../../wip/ccrtp/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBZRTPCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzrtpcpp
