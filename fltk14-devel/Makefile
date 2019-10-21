# $NetBSD$

DISTNAME=	fltk-1.4.x
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fltk/}
GITHUB_TAG=	940b7ba13d26dcde4fbd4574d56167501e598327
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake nroff
# Doesn't run tests, only build them (because they are GUI programs)
TEST_TARGET=		test

.include "options.mk"

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-print
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-xcursor
CONFIGURE_ARGS+=	--enable-xfixes
CONFIGURE_ARGS+=	--enable-xrender

# Use pkgsrc versions of libraries, not package's bundled versions.
CONFIGURE_ARGS+=	--disable-localjpeg
CONFIGURE_ARGS+=	--disable-localpng
CONFIGURE_ARGS+=	--disable-localzlib

# Create symlinks for common misspellings of headerfile names
# (if filesystem is case-sensitive)
PLIST_VARS+=		cs	# case-sensitive
.if !exists(./descr) && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-links
PLIST.cs=		yes
.endif

# ------------------------------------------------------
# No documentation where and why this was needed for FLTK 1.3 package
# => Comment out for tests. Reenabled if problem still exists.
#CONFIGURE_ARGS+=	ac_cv_have_overlay=yes
# ------------------------------------------------------

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

# FLTK uses Cocoa backend on macOS/Darwin (X11 backend otherwise)
.if ${OPSYS} != "Darwin"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
