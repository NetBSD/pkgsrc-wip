# $NetBSD: Makefile,v 1.1.1.1 2005/09/02 19:12:40 tnn2 Exp $
#

DISTNAME=	zidrav4unix-1.2.0
PKGNAME=	zidrav-1.20
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zidrav/}

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://sourceforge.net/projects/zidrav
COMMENT=	file corruption detection and repair program

USE_LANGUAGES=  c c++
BUILD_TARGET=	zidrav

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
  CXXFLAGS+=-DCPU_BIGENDIAN
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${PREFIX}/bin/zidrav
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${PREFIX}/man/man1/zidrav.1

.include "../../mk/bsd.pkg.mk"
