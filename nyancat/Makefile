# $NetBSD$

DISTNAME=	nyancat-1.5.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=klange/}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	http://nyancat.dakko.us/
COMMENT=	Nyancat in your terminal
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nyancat ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nyancat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
