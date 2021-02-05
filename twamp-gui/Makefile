# $NetBSD$

DISTNAME=	twamp-gui-1.0.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=demirten/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/demirten/twamp-gui
COMMENT=	GUI for doing and visualizing TWAMP measurement
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++


MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QTDIR}/bin/qmake twamp-gui.pro PREFIX=${PREFIX}

INSTALLATION_DIRS+=	bin

PROGS=	client/twamp-client responder/twamp-responder

do-install:
	cd ${WRKSRC} && \
	for f in ${PROGS}; do \
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/bin; \
	done

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
