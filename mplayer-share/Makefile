# $NetBSD: Makefile,v 1.3 2006/04/20 13:36:38 cheusov Exp $

.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_PKG_VERSION}
COMMENT=	Documentation used by mplayer and gmplayer

DEPENDS+=	mplayer-fonts-[0-9]*:../../fonts/mplayer-fonts

NO_BUILD=	YES
NO_CONFIGURE=	YES

CVS_REPOSITORIES=	mplayer
CVS_ROOT.mplayer=	:pserver:anonymous:@mplayerhq.hu:/cvsroot/mplayer
CVS_MODULE.mplayer=	main

.include "../../wip/mk/cvs-package.mk"

INSTALLATION_DIRS=	man/man1

post-extract:
	${FIND} ${WRKDIR} -type d -name CVS | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/DOCS
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${PREFIX}/share/mplayer
	(cd ${WRKSRC}/DOCS && \
		${PAX} -rwpppm * ${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${PREFIX}/share/mplayer/DOCS -type d -exec ${CHMOD} \
     		${PKGDIRMODE} \{\} \;
	${FIND} ${PREFIX}/share/mplayer/DOCS -type f -exec ${CHMOD} \
  		${SHAREMODE} \{\} \;

.include "../../mk/bsd.pkg.mk"
