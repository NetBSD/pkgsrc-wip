# $NetBSD: Makefile,v 1.3 2004/10/20 15:02:43 lexort Exp $

DISTNAME=	guile-lib-0.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

# Because the distribution does not specify a version, accept anything
# from 1.6 onwards.
DEPENDS+=	guile>=1.6:../../lang/guile

HAS_CONFIGURE=	yes
#CONFIGURE_SCRIPT=	../src/configure
#CONFIGURE_ARGS= --prefix=${LOCALBASE}
USE_GNU_TOOLS=	make

USE_MAKEINFO=	yes
INFO_FILES=	guile-library.info

# This package has split src/build directories, and there does not
# seem to be explicit support for this in pkgsrc.  Thus, all the targets
# below are overridden.

pre-configure:
	${MKDIR} ${WRKSRC}/build

do-configure:
	cd ${WRKSRC}/build && ../src/configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC}/build && ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
