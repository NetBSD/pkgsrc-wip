# $NetBSD: Makefile,v 1.19 2009/12/14 23:37:53 lexort Exp $
#

DISTNAME=		grass-${GRASS_VERSION}
PKGREVISION=		2
CATEGORIES=		geography
MASTER_SITES=		http://grass.itc.it/grass63/source/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://grass.itc.it/
COMMENT=		Open source geographical information system (GIS)

USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_TOOLS+=		autoconf bash gm4 gmake perl
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes

BUILDLINK_PASSTHRU_RPATHDIRS+=	${GRASS_HOME}/lib

.include "options.mk"

PLIST_VARS+=		fftw freetype iodbc motif mysql
PLIST_VARS+=		nls opengl pgsql sqlite unixodbc

CONFIGURE_ARGS+=	--with-cxx
CONFIGURE_ARGS+=	--without-opendwg
CONFIGURE_ARGS+=	--with-proj-share=${PREFIX}/share/proj
CONFIGURE_ARGS+=	--with-readline

REPLACE_BASH+=		scripts/i.spectral/i.spectral
REPLACE_BASH+=		scripts/r.tileset/r.tileset
REPLACE_BASH+=		scripts/v.in.gpsbabel/v.in.gpsbabel

REPLACE_PYTHON+=	gui/wxpython/gui_modules/menuform.py

BUILD_TARGET=		default

# Note - the following is because the grass build process involves
# installing compiled objects into a directory within ${WRKSRC};
# during installation, files are installed from there into ${PREFIX}.
# However, because the install command changes ownership (even during
# the build phase), the package cannot be built by a non-root user.
pre-extract:
	@if [ `${ID} -u` != 0 ]; then \
	  ${ECHO} "${PKGNAME} must be built as root because it uses install during build." ; \
	  ${FALSE}; fi

post-install:
	${LN} -s grass${GRASS_VERSION:C/\.[0-9]+\$$//:S/.//g} \
		${PREFIX}/bin/grass

.include "Makefile.common"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
