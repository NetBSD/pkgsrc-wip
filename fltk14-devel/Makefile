# $NetBSD$

DISTNAME=	fltk-1.4.x
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fltk/}
GITHUB_TAG=	6ed7b56c798eea9ae36cfcc88c33235a26c9932d
EXTRACT_SUFX=	.zip

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99
FORCE_C_STD=		c99
FORCE_CXX_STD=		c++98

USE_TOOLS+=		autoconf gmake nroff pkg-config
USE_LIBTOOL=		yes

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-print
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-svg
CONFIGURE_ARGS+=	--enable-threads

# Use pkgsrc versions of libraries, not package's bundled versions
CONFIGURE_ARGS+=	--disable-localjpeg
CONFIGURE_ARGS+=	--disable-localpng
CONFIGURE_ARGS+=	--disable-localzlib

# Disable build of test programs
CONFIGURE_ARGS+=	--disable-test

.include "options.mk"

# ------------------------------------------------------
# Clean the source tree first for snapshots
# (CPPFLAGS/LDFLAGS are for modular X)
# => Remove this section for release version
pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC} && \
		CPPFLAGS="-I ${PREFIX}/include" LDFLAGS="-L ${PREFIX}/lib" \
		${GMAKE} ${MAKE_FLAGS} clean
# ------------------------------------------------------

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
