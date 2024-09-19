# $NetBSD$

PKGNAME=	conkeror-1.0.4
DISTNAME=	685f24e3aeffc408dcea883e1d0c738cb18bbe8d
CATEGORIES=	www
MASTER_SITES=	http://repo.or.cz/conkeror.git/snapshot/
DIST_SUBDIR=	conkeror

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.conkeror.org/
COMMENT=	Extensible keyboard-oriented web browser based on Mozilla
LICENSE=	mpl-1.1

WRKSRC=	${WRKDIR}/conkeror-685f24e

DEPENDS+=	firefox45-[0-9]*:../../www/firefox45

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications

#post-patch:
#	${RM} ${WRKSRC}/modules/*.orig \
#		${WRKSRC}/modules/page-modes/*.orig \
#		${WRKSRC}/search-engines/*.orig

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
