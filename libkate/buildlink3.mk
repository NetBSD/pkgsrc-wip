# $NetBSD: buildlink3.mk,v 1.1 2013/03/03 00:01:24 othyro Exp $

BUILDLINK_TREE+=	libkate

.if !defined(LIBKATE_BUILDLINK3_MK)
LIBKATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkate+=	libkate>=0.4.1
BUILDLINK_PKGSRCDIR.libkate?=	../../wip/libkate

pkgbase := libkate
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libkate:Moggz)
.include "../../wip/liboggz/buildlink3.mk"
.endif

.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif	# LIBKATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkate
