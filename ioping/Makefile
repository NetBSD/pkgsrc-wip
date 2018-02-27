# $NetBSD$

CATEGORIES=	net

COMMENT=	Monitor I/O latency in real time
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	ioping
GITHUB_TAG=	v1.0
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=koct9i/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/koct9i/ioping/

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV:S/v//}

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../mk/bsd.pkg.mk"
