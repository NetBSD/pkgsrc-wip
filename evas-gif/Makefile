# $NetBSD: Makefile,v 1.1 2012/12/30 19:29:59 roelants Exp $

PKGNAME=	evas-gif-${EVAS_VERSION}

COMMENT=	Evas GIF image loader

EVAS_IMAGE_LOADERS=	gif

.include "../../wip/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/gif
MAKE_FLAGS+=	module_la_DEPENDENCIES= \
		module_la_LIBADD="\$${EINA_LIBS} \$${evas_image_loader_gif_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
