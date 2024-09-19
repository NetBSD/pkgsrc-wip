# $NetBSD: Makefile,v 1.1 2014/06/05 23:35:52 yrmt Exp $

DISTNAME=	geekcode-1.7.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geekcode/}

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	https://sourceforge.net/projects/geekcode/
COMMENT=	The Geek Code Generator
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekcode ${DESTDIR}${PREFIX}/bin/geekcode

.include "../../mk/bsd.pkg.mk"
