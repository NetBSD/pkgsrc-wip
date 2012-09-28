# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:30 asau Exp $
#

DISTNAME=	datapipe-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.distributed.net/dcti/unsupported/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	ftp://ftp.distributed.net/dcti/unsupported/
COMMENT=	Bind a local port and connect it to a remote socket

do-build:
	${CC} -o ${WRKSRC}/datapipe ${WRKSRC}/datapipe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datapipe ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
