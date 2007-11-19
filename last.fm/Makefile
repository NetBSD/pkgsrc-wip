# $NetBSD: Makefile,v 1.1.1.1 2007/11/19 22:02:45 netcap Exp $
#

PKGNAME=	last.fm-1.3.2.13
DISTNAME=	${PKGNAME}.src
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/client/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.last.fm/
COMMENT=	Official last.fm radio player

BROKEN=		Needs some more love
WRKSRC=		${WRKDIR}/last.fm-1.3.2.13
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS=	make

QMAKE=		${QTDIR}/bin/qmake
DATADIR=	${PREFIX}/share/last.fm

post-patch:
	${SED} -e 's|linux\*|unix|g' ${WRKSRC}/src/src.pro

do-build:
	cd ${WRKSRC} && \
		${QMAKE} -config release -after "CONFIG-=debug" && ${MAKE_ENV} make
	cd ${WRKSRC}/src/output/RtAudio && \
	${SETENV} ${CONFIGURE_ENV} ${QMAKE} -spec netbsd-g++ && ${MAKE_ENV} make
	cp ${WRKSRC}/bin/last.fm ${WRKSRC}/bin/last.fm.dist
	${SED} -e"s|^RUNDIR.*|RUNDIR=${DATADIR}|" \
		${WRKSRC}/bin/last.fm.dist > ${WRKSRC}/bin/last.fm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/last.fm ${PREFIX}/bin/last.fm
.for d in ${DATADIR} ${DATADIR}/data ${PREFIX}/share/services
	${INSTALL_DATA_DIR} ${d}
.endfor
	${INSTALL_DATA} ${FILESDIR}/lastfm.protocol ${PREFIX}/share/services
	cd ${WRKSRC}/bin && ${PAX} -rwpp . ${DATADIR}/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
