# $NetBSD: Makefile,v 1.3 2003/07/02 09:43:24 blef Exp $
#

DISTNAME=	allegro-4.1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

MAKEFILE=		makefile
ALL_TARGET=		# there is no 'all' target for some reason
USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
INFO_FILES=		allegro.info
INSTALL_TARGET=		install install-info

# build debugging lib
CONFIGURE_ARGS+=	--enable-dbglib

# NetBSD's OSS midi emulation is non-existant.
CONFIGURE_ARGS+=	--disable-ossmidi
# Following three only exist as static libraries, but will be linked
# into shared library by allegro if enabled.
CONFIGURE_ARGS+=	--disable-xwin-vidmode
CONFIGURE_ARGS+=	--disable-xwin-dga
CONFIGURE_ARGS+=	--disable-xwin-dga2

LIBS+=		${LIBOSSAUDIO}

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
