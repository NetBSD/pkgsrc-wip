# $NetBSD: buildlink3.mk,v 1.2 2011/02/23 13:59:46 makoto Exp $

BUILDLINK_TREE+=	ghostscript

.if !defined(GHOSTSCRIPT_BUILDLINK3_MK)
GHOSTSCRIPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghostscript+=	ghostscript>=8.63nb1
BUILDLINK_ABI_DEPENDS.ghostscript?=	ghostscript>=8.71nb7
BUILDLINK_PKGSRCDIR.ghostscript?=	../../wip/ghostscript

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := ghostscript
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mcups)
.include "../../print/cups/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif
.endif # GHOSTSCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghostscript
