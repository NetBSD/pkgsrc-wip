# $NetBSD: Makefile,v 1.1.1.1 2004/10/19 16:54:01 lexort Exp $

DISTNAME=	guile-lib-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

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

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
