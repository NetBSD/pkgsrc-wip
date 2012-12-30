# $NetBSD: buildlink3.mk,v 1.1 2012/12/30 01:56:46 othyro Exp $

BUILDLINK_TREE+=	libticalcs2

.if !defined(LIBTICALCS2_BUILDLINK3_MK)
LIBTICALCS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticalcs2+=	libticalcs2>=1.1.7
BUILDLINK_PKGSRCDIR.libticalcs2?=	../../wip/libticalcs2

pkgbase := libticalcs2
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.libticalcs2:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../wip/libtifiles2/buildlink3.mk"
.include "../../wip/libticonv/buildlink3.mk"
.include "../../wip/libticables2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTICALCS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticalcs2
