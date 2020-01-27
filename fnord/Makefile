# $NetBSD: Makefile,v 1.11 2014/06/01 12:49:35 thomasklausner Exp $

DISTNAME=	fnord-1.11
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://www.fefe.de/fnord/
COMMENT=	Small HTTP server
LICENSE=	gnu-gpl-v2

# web server Gatling running at www.fefe.de is incompatible with BSD ftp
# cf. PR#45516
USE_TOOLS+=	gmake
DEPENDS+=	{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp

CFLAGS+=	${CPPFLAGS}
MAKE_ENV+=	RANLIB=${RANLIB:Q} LIBS=${LIBS:Q}

.if exists(/usr/include/alloca.h)
CPPFLAGS+=	-DNEED_ALLOCA_H
.endif

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	sbin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} fnord fnord-cgi fnord-idx ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
