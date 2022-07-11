# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake tar

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

BUILD_TARGET=	compile
INSTALL_TARGET=	deploy source-package

EGDIR=		share/jitsi-meet
PKG_SYSCONFSUBDIR= jitsi/meet
CONF_FILES=	${EGDIR}/config.js ${PKG_SYSCONFDIR}/config.js
CONF_FILES+=	${EGDIR}/interface_config.js \
		${PKG_SYSCONFDIR}/interface_config.js
CONF_FILES+=	${EGDIR}/title.html ${PKG_SYSCONFDIR}/title.html

INSTALLATION_DIRS=	${EGDIR} share/examples/jitsi-meet

BUILD_DEFS+=		VARBASE

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-stable-${DISTNAME}

do-configure:
	cd ${WRKSRC} && \
		npm install

post-install:
	${RUN} ${TAR} -C ${DESTDIR}${PREFIX}/share -xjf ${WRKSRC}/jitsi-meet.tar.bz2
	${INSTALL_DATA} ${WRKSRC}/config.js \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/config.js
	${INSTALL_DATA} ${WRKSRC}/interface_config.js \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/interface_config.js
	${INSTALL_DATA} ${WRKSRC}/title.html \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/title.html

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/bsd.pkg.mk"
