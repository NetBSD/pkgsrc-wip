# $NetBSD$

GITHUB_PROJECT=	ioping
DISTNAME=	v1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=koct9i/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/koct9i/ioping/
COMMENT=	Monitor I/O latency in real time
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${PKGNAME:S/v//}

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../mk/bsd.pkg.mk"
