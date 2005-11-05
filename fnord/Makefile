# $NetBSD: Makefile,v 1.4 2005/11/05 17:30:54 gschwarz Exp $

DISTNAME=	fnord-1.10
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fefe.de/fnord/
COMMENT=	Small HTTP server

USE_TOOLS+=	gmake
DEPENDS+=	ucspi-tcp-*:../../net/ucspi-tcp

.if exists(/usr/include/alloca.h)
CFLAGS+=	-DNEED_ALLOCA_H
.endif

INSTALLATION_DIRS=	sbin

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} fnord fnord-cgi fnord-idx ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
