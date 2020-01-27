# $NetBSD: Makefile,v 1.2 2012/11/02 19:51:25 othyro Exp $
#

DISTNAME=	irrxml-1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=irrlicht/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ambiera.com/irrxml/
COMMENT=	Simple and fast open source xml parser for C++
LICENSE=	zlib

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	include/irrXML


do-install:
	cd ${WRKSRC} && \
	for file in src/irrXML.cpp src/*.h; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/include/irrXML; \
	done


.include "../../mk/bsd.pkg.mk"
