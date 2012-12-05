# $NetBSD: buildlink3.mk,v 1.1 2012/12/05 04:40:20 othyro Exp $

BUILDLINK_TREE+=	libbfio

.if !defined(LIBBFIO_BUILDLINK3_MK)
LIBBFIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbfio+=	libbfio>=20120425
BUILDLINK_PKGSRCDIR.libbfio?=	../../wip/libbfio

pkgbase := libbfio
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.libbfio:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../wip/libuna/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBBFIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbfio
