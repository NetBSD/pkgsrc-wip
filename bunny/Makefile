# $NetBSD: Makefile,v 1.2 2010/04/16 20:51:46 jihbed Exp $
#

DISTNAME=	bunny-0.93
CATEGORIES=	security
MASTER_SITES=	http://bunny-the-fuzzer.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/bunny-the-fuzzer/
COMMENT=	Tools with C code security fuzzer
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/bunny
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

BUNNY_FILES=	bunny-exec bunny-flow bunny-gcc bunny-main bunny-trace

do-install:
	for a in ${BUNNY_FILES}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/bin/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
