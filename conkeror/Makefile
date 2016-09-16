# $NetBSD$

PKGNAME=	conkeror-1.0.3
DISTNAME=	11121bed996ce84e3536c3c8266cdf3164e02b5a
CATEGORIES=	www
MASTER_SITES=	http://repo.or.cz/conkeror.git/snapshot/
DIST_SUBDIR=	conkeror

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.conkeror.org/
COMMENT=	Extensible keyboard-oriented web browser based on Mozilla
LICENSE=	mpl-1.1

WRKSRC=	${WRKDIR}/conkeror-11121be

DEPENDS+=	firefox-[0-9]*:../../www/firefox

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
