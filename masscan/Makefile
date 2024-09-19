# $NetBSD$

DISTNAME=	masscan-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=robertdavidgraham/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/robertdavidgraham/masscan/
COMMENT=	TCP port scanner, spews SYN packets asynchronously
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/masscan ${DESTDIR}${PREFIX}/bin/masscan
	${INSTALL_MAN} ${WRKSRC}/doc/masscan.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/pthread.buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
