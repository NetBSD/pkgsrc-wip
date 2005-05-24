# $NetBSD: Makefile,v 1.2 2005/05/24 10:29:42 rillig Exp $

DISTNAME=	fnord-1.9
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fefe.de/fnord/
COMMENT=	A small HTTP server

USE_TOOLS+=	gmake
DEPENDS+=	ucspi-tcp-*:../../net/ucspi-tcp

INSTALLATION_DIRS=	sbin

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} fnord fnord-cgi fnord-idx ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
