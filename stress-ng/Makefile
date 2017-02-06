# $NetBSD$

DISTNAME=	stress-ng-0.05.18
CATEGORIES=	benchmark
MASTER_SITES=	http://kernel.ubuntu.com/~cking/tarballs/stress-ng/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kernel.ubuntu.com/~cking/stress-ng/
COMMENT=	Stress test benchmarks
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
BUILD_TARGET=	install

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/stress-ng ${DESTDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/stress-ng.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
