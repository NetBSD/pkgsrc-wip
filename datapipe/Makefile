# $NetBSD: Makefile,v 1.4 2013/03/21 17:34:50 shattered Exp $
#

DISTNAME=	datapipe-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.distributed.net/dcti/unsupported/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	ftp://ftp.distributed.net/dcti/unsupported/
COMMENT=	Bind a local port and connect it to a remote socket

INSTALLATION_DIRS=	bin

do-build:
	${CC} -o ${WRKSRC}/datapipe ${WRKSRC}/datapipe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datapipe ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
