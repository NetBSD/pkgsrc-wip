# $NetBSD: buildlink3.mk,v 1.3 2013/07/04 21:27:58 adam Exp $

BUILDLINK_TREE+=	libquvi

.if !defined(LIBQUVI_BUILDLINK3_MK)
LIBQUVI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquvi+=	libquvi>=0.9.0
BUILDLINK_ABI_DEPENDS.libquvi+=	libquvi>=0.9.0
BUILDLINK_PKGSRCDIR.libquvi?=	../../wip/libquvi

.include "../../lang/lua/buildlink3.mk"
.include "../../wip/libquvi-scripts/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.endif	# LIBQUVI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libquvi
