# $NetBSD: Makefile,v 1.6 2012/10/03 14:36:41 asau Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
COMMENT=	Documentation used by mplayer and gmplayer

DEPENDS+=	mplayer-fonts-[0-9]*:../../fonts/mplayer-fonts

NO_BUILD=	YES
NO_CONFIGURE=	YES
USE_TOOLS+=	pax

CVS_REPOSITORIES=	mplayer
CVS_ROOT.mplayer=	:pserver:anonymous:@mplayerhq.hu:/cvsroot/mplayer
CVS_MODULE.mplayer=	main

.include "../../wip/mk/cvs-package.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mplayer/DOCS
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${DESTDIR}${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${DESTDIR}${PREFIX}/share/mplayer
	(cd ${WRKSRC}/DOCS && \
		pax -rwpppm * ${DESTDIR}${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type d -exec ${CHMOD} \
		${PKGDIRMODE} \{\} \;
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type f -exec ${CHMOD} \
		${SHAREMODE} \{\} \;

.include "../../mk/bsd.pkg.mk"
