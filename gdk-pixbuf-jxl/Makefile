# $NetBSD$

.include "../../wip/libjxl/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/gdk-pixbuf-/g}
COMMENT=	JpegXL GDK pixbuf loader

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	bash pkg-config realpath
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CONFIGURE_DIRS=	plugins/gdk-pixbuf
BUILD_DIRS=	plugins/gdk-pixbuf

REPLACE_BASH=	deps.sh

SUBST_CLASSES+=		gpt
SUBST_STAGE.gpt=	pre-configure
SUBST_MESSAGE.gpt=	Fixing path to gdk-pixbuf-thumbnailer
SUBST_FILES.gpt=	plugins/gdk-pixbuf/jxl.thumbnailer
SUBST_SED.gpt=		-e 's,/usr,${PREFIX},g'

CMAKE_USE_GNU_INSTALL_DIRS=	no

# TODO:
# The dependencies installed using deps.sh should be packaged
# and buildlink3ed 
# the next version 0.9 depends on lcms2 instead of skcms
pre-configure:
	cd ${WRKSRC} && ./deps.sh

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
.include "../../wip/libjxl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
