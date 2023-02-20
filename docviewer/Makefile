# $NetBSD$
#

DISTNAME=	docviewer-0.2.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	3bb75e957ebe00cf99d3893bc1f2ed9e647112da

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Generic command to automatically select a document viewer
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docviewer ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docviewer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
