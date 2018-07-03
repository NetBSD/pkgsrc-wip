# $NetBSD: buildlink3.mk,v 1.2 2012/12/29 01:11:15 othyro Exp $

BUILDLINK_TREE+=	libinstpatch

.if !defined(LIBINSTPATCH_BUILDLINK3_MK)
LIBINSTPATCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinstpatch+=	libinstpatch>=1.0.0
BUILDLINK_PKGSRCDIR.libinstpatch?=	../../wip/libinstpatch

pkgbase := libinstpatch
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libinstpatch:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libinstpatch:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../devel/py-gobject/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBINSTPATCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinstpatch
