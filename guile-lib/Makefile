# $NetBSD: Makefile,v 1.5 2004/11/10 18:03:29 lexort Exp $

DISTNAME=	guile-lib-0.1.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

# Because the distribution does not specify a version, accept anything
# from 1.6 onwards.
DEPENDS+=	guile>=1.6:../../lang/guile

# This package may not be built from the src directory (arch configure
# rules).  The build directory must be created by hand; see the
# pre-configure target.
HAS_CONFIGURE=	yes
CONFIGURE_DIRS=	${WRKSRC}/build
BUILD_DIRS=	${WRKSRC}/build
CONFIGURE_SCRIPT=	../src/configure
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_GNU_TOOLS=	make

pre-configure:
	${MKDIR} ${WRKSRC}/build


USE_MAKEINFO=	yes
INFO_FILES=	guile-library.info

.include "../../mk/bsd.pkg.mk"
