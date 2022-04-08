# $NetBSD$

DISTNAME=	fox-1.7.79
CATEGORIES=	x11
MASTER_SITES=	ftp://www.fox-toolkit.org/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-xft
CONFIGURE_ARGS+=	--with-x

.include "../../mk/bsd.prefs.mk"

# Only Linux and FreeBSD support
.if ${OPSYS} != "Linux" && ${OPSYS} != "FreeBSD"
CONFIGURE_ENV+=		ac_cv_func_pthread_setaffinity_np=no
.endif

# Disable generic codepath for pthread_setname_np()
# This is a nonportable function and needs explicit support
CONFIGURE_ENV+=		ac_cv_func_pthread_setname_np=no

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
