# $NetBSD$

BUILDLINK_TREE+=	gnurl

.if !defined(GNURL_BUILDLINK3_MK)
GNURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnurl+=	gnurl>=7.12.3
BUILDLINK_ABI_DEPENDS.gnurl+=	gnurl>=7.61.0nb2
BUILDLINK_PKGSRCDIR.gnurl?=	../../wip/gnurl

pkgbase:= gnurl
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GNURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnurl
