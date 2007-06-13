# $NetBSD: options.mk,v 1.1 2007/06/13 12:10:36 ondratu Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-commander
PKG_SUPPORTED_OPTIONS=	python exif cms id3 chm gsf
PKG_SUGGESTED_OPTIONS=	python exif cms id3 chm gsf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/application.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.python
.endif

.if !empty(PKG_OPTIONS:Mexif)
.include "../../graphics/libexif/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcms)
.include "../../graphics/lcms/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mid3)
.include "../../audio/id3lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mchm)
.include "../../devel/chmlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgsf)
.include "../../devel/libgsf/buildlink3.mk"
.endif
