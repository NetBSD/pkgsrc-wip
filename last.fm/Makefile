# $NetBSD: Makefile,v 1.6 2012/10/01 22:15:52 asau Exp $
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	last.fm-1.3.2.13
PKGREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/client/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.last.fm/
COMMENT=	Official last.fm radio player

BROKEN=		FIXME: I build fine now, but fail to load some libs.
WRKSRC=		${WRKDIR}/last.fm-1.3.2.13
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pax

QMAKE=		${QTDIR}/bin/qmake
LFMDATA=	${PREFIX}/share/last.fm

SUBST_CLASSES+=			rundir
SUBST_MESSAGE.rundir=		Correcting rundir.
SUBST_STAGE.rundir=		post-build
SUBST_FILES.rundir=		bin/last.fm
SUBST_SED.rundir=		-e 's|^RUNDIR.*|RUNDIR=${LFMDATA}|'

do-build:
	cd ${WRKSRC} && \
		${QMAKE} -config release -after "CONFIG-=debug" && ${MAKE_ENV} make
	cd ${WRKSRC}/src/output/RtAudio && \
	env ${CONFIGURE_ENV} ${QMAKE} -spec netbsd-g++ && env ${MAKE_ENV} make

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/last.fm ${DESTDIR}${PREFIX}/bin/last.fm
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/last.fm
	cd ${WRKSRC}/bin/.libs && pax -rwpp . ${DESTDIR}${PREFIX}/lib/last.fm
	${INSTALL_DATA_DIR} ${DESTDIR}${LFMDATA}
	${INSTALL_DATA_DIR} ${DESTDIR}${LFMDATA}/data
	${INSTALL_DATA_DIR} ${DESTDIR}${LFMDATA}/services
	${INSTALL_DATA} ${FILESDIR}/lastfm.protocol ${DESTDIR}${LFMDATA}/services
	cd ${WRKSRC}/bin && pax -rwpp . ${DESTDIR}${LFMDATA}/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
