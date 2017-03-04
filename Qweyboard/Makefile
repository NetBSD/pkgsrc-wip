# $NetBSD$

DISTNAME=	Qweyboard-0.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=kqr/}

GIT_REPOSITORIES=	qweyboard
GIT_REPO.qweyboard=	https://github.com/kqr/qweyboard.git
WRKSRC=			${WRKDIR}/qweyboard

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/kqr/qweyboard
COMMENT=	Velotype/Veyboard like experience on a regular computer keyboard
LICENSE=	isc

USE_LANGUAGES=	ada
USE_TOOLS+=	gmake

AUTO_MKDIRS=	yes

SUBST_CLASSES+=			add-paths
SUBST_STAGE.add-paths=		pre-configure
SUBST_MESSAGE.add-paths=	Adding link path to X11 libraries.
SUBST_FILES.add-paths+=		Makefile
SUBST_SED.add-paths+=		-e 's|CFLAGS=|CFLAGS=-L${X11USRLIBDIR} |g'

do-install:
	${INSTALL_ENV} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qweyboard ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXtst/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
