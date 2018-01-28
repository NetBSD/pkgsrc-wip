# $NetBSD: Makefile,v 1.5 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	qmpdclient-1.1.2
PKGREVISION=	3

CATEGORIES=	audio
MASTER_SITES=	http://dump.bitcheese.net/files/dedycec/
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/qmpdclient

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://bitcheese.net/wiki/QMPDClient
COMMENT=	QT4 based mpd client
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		fix-proj
SUBST_STAGE.fix-proj=	post-patch
SUBST_MESSAGE.fix-proj=	Fixing qmake project file.
SUBST_FILES.fix-proj=	qmpdclient.pro
SUBST_SED.fix-proj=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-proj+=	-e 's,lrelease,${QTDIR}/bin/lrelease,g'
SUBST_SED.fix-proj+=	-e 's,-g0 -s,,g'

MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
QMAKE_FLAGS+=	QT_CONFIG=${QT_CONFIG:Q}

# qmake isn't smart enough to integrate with lrelease. We have to run
# it before actually invoking qmake, or lang/*.qm won't be installed.
pre-configure:
	${RUN} cd ${WRKSRC} && \
		${QTDIR}/bin/lrelease lang/*.ts

do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake ${QMAKE_FLAGS}

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
