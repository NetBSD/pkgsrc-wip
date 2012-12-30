# $NetBSD: Makefile,v 1.1 2012/12/30 19:31:53 roelants Exp $

PKGNAME=	evas-xpm-${EVAS_VERSION}

COMMENT=	Evas XPM image loader

EVAS_IMAGE_LOADERS=	xpm

.include "../../wip/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/xpm
MAKE_FLAGS+=	module_la_DEPENDENCIES= \
		module_la_LIBADD="\$${EVAS_GENERAL_LIBS} \$${EVIL_LIBS} \$${evas_image_loader_xpm_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
