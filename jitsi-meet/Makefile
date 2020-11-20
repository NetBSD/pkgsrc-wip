# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}

COMMENT=	Secure, Simple and Scalable Video Conferences

WRKSRC=		${WRKDIR}/jitsi-meet-${DISTNAME}
USE_TOOLS=	gmake tar

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

BUILD_TARGET=	compile
INSTALL_TARGET=	deploy source-package

EGDIR=		share/jitsi-meet
CONF_FILES=	${EGDIR}/config.js ${PKG_SYSCONFDIR}/jitsi/meet/config.js
CONF_FILES+=	${EGDIR}/interface_config.js ${PKG_SYSCONFDIR}/jitsi/meet/interface_config.js
CONF_FILES+=	${EGDIR}/title.html ${PKG_SYSCONFDIR}/jitsi/meet/title.html

INSTALLATION_DIRS=	${EGDIR}

do-configure:
	cd ${WRKSRC} && \
		npm install

post-install:
	${RUN} ${TAR} -C ${DESTDIR}${PREFIX}/share -xjf ${WRKSRC}/jitsi-meet.tar.bz2

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
