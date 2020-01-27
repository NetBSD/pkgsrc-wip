# $NetBSD: Makefile,v 1.1 2014/05/16 14:18:33 thomasklausner Exp $

DISTNAME=	rtspdump
PKGNAME=	${DISTNAME}-2.7
CATEGORIES=	net multimedia
MASTER_SITES=	http://bisqwit.iki.fi/src/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bisqwit.iki.fi/src/
COMMENT=	Download multimedia stream from a Microsoft Windows Media Server
LICENSE=	zlib

DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# php

INSTALLATION_DIRS+=	bin share/rtspdump

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/rtspdump
	${ECHO} "cd ${PREFIX}/share/rtspdump && ${PREFIX}/bin/php rtspdump.php "'"$$@"' >> ${WRKSRC}/rtspdump

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rtspdump ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${DESTDIR}${PREFIX}/share/rtspdump

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
