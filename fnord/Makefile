# $NetBSD: Makefile,v 1.8 2011/01/16 17:49:52 gschwarz Exp $

DISTNAME=	fnord-1.10
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fefe.de/fnord/
COMMENT=	Small HTTP server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
DEPENDS+=	ucspi-tcp-*:../../net/ucspi-tcp

CFLAGS+=	${CPPFLAGS}
MAKE_ENV+=	RANLIB=${RANLIB:Q} LIBS=${LIBS:Q}

.if exists(/usr/include/alloca.h)
CPPFLAGS+=	-DNEED_ALLOCA_H
.endif

LIBS.SunOS+=	-lsocket  -lnsl

INSTALLATION_DIRS=	sbin

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} fnord fnord-cgi fnord-idx ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
