# $NetBSD$

.include "../../wip/libjxl/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/gdk-pixbuf-/g}
COMMENT=	JpegXL GDK pixbuf loader

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	bash pkg-config
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

pre-configure:
	cd ${WRKSRC} && ./deps.sh

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
.include "../../wip/libjxl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
