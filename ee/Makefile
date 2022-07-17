# $NetBSD$

DISTNAME=	ee-1.5.2.src
PKGNAME=	${DISTNAME:S,.src,,}
CATEGORIES=	editors
MASTER_SITES=	http://web.archive.org/web/20120716042037/http://mahon.cwx.net/sources/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://www.ucl.ac.uk/~ccaabaa/is/unix/ee.htm
COMMENT=	EasyEdit, a classic curses text editor
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes     # fixterm()

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/easyedit-1.5.2

post-configure:
	cd ${WRKSRC} && ${MAKE:Q} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ee.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
