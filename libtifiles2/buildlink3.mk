# $NetBSD: buildlink3.mk,v 1.1 2012/12/30 01:46:38 othyro Exp $

BUILDLINK_TREE+=	libtifiles2

.if !defined(LIBTIFILES2_BUILDLINK3_MK)
LIBTIFILES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtifiles2+=	libtifiles2>=1.1.5
BUILDLINK_PKGSRCDIR.libtifiles2?=	../../wip/libtifiles2

pkgbase := libtifiles2
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.libtifiles2:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libticonv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTIFILES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles2
