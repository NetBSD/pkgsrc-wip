# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

USE_TOOLS=	gmake tar

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

BUILD_TARGET=	compile
INSTALL_TARGET=	deploy source-package

EGDIR=		share/jitsi-meet
CONF_FILES=	${EGDIR}/config.js ${PKG_SYSCONFDIR}/jitsi/meet/config.js
CONF_FILES+=	${EGDIR}/interface_config.js ${PKG_SYSCONFDIR}/jitsi/meet/interface_config.js
CONF_FILES+=	${EGDIR}/title.html ${PKG_SYSCONFDIR}/jitsi/meet/title.html

INSTALLATION_DIRS=	${EGDIR} share/examples/jitsi-meet

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/example-config-files/nginx.conf.example
SUBST_FILES.paths+=	doc/example-config-files/jitsi.example.com.example
SUBST_FILES.paths+=	doc/example-config-files/prosody.cfg.lua.example
SUBST_SED.paths=	-e 's,/etc/,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/srv/.*;,${PREFIX}/${EGDIR};,g'
SUBST_SED.paths+=	-e 's,/var/,${VARBASE},g'

do-configure:
	cd ${WRKSRC} && \
		npm install

post-install:
	${RUN} ${TAR} -C ${DESTDIR}${PREFIX}/share -xjf ${WRKSRC}/jitsi-meet.tar.bz2
	${INSTALL_DATA} ${WRKSRC}/doc/example-config-files/config.js.example \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/config.js
	${INSTALL_DATA} ${WRKSRC}/doc/example-config-files/jitsi.example.com.example \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/jitsi.example.com
	${INSTALL_DATA} ${WRKSRC}/doc/example-config-files/nginx.conf.example \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/nginx.conf
	${INSTALL_DATA} ${WRKSRC}/doc/example-config-files/prosody.cfg.lua.example \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/prosody.cfg.lua

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
