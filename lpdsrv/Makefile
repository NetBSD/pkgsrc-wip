# $NetBSD: Makefile,v 1.3 2011/01/18 21:13:53 gschwarz Exp $

DISTNAME=	${PKGNAME:C/-.*$//}
PKGNAME=	lpdsrv-1.4
CATEGORIES=	net
MASTER_SITES=	http://www.ledow.org.uk/Freesco/Programs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	Non-spooling LPD server (RFC1179)

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES
WRKSRC=		${WRKDIR}
EXTRACT_USING=	gtar # archive does not properly extract using BSD tar

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	LDLIBS=${LIBS:Q}

INSTALLATION_DIRS=	sbin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/lpdsrv ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
