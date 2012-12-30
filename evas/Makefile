# $NetBSD: Makefile,v 1.31 2012/12/30 19:28:50 roelants Exp $
#

COMMENT=	Canvas and scenegraph rendering library

EVAS_IMAGE_LOADERS=	eet jpeg pmaps png bmp tga wbmp ico psd generic

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	evas.pc.in evas-software-buffer.pc.in

INSTALLATION_DIRS=	lib/evas/modules/loaders lib/evas/modules/savers \
			share/doc/evas

.include "../../mk/bsd.prefs.mk"

PLIST_SRC+=	PLIST
.if ${OPSYS} != "NetBSD" && ${OPSYS} != "OpenBSD" && ${OPSYS} != "MirBSD"
PLIST_SRC+=	PLIST.cserve
.endif

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/evas

#.include "../../converters/fribidi/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
