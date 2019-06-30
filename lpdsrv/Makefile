# $NetBSD: Makefile,v 1.4 2012/10/03 09:10:43 asau Exp $

DISTNAME=	${PKGNAME:C/-.*$//}
PKGNAME=	lpdsrv-1.4
CATEGORIES=	net
MASTER_SITES=	http://www.ledow.org.uk/Freesco/Programs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	Non-spooling LPD server (RFC1179)

NO_CONFIGURE=	YES
WRKSRC=		${WRKDIR}
EXTRACT_USING=	gtar # archive does not properly extract using BSD tar

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	LDLIBS=${LIBS:Q}

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lpdsrv ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
