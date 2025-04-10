# $NetBSD$

.include "../../chat/jitsi-meet/Makefile.common"

PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}
PKGREVISION=	1

# Makefile.common sets DISTINFO_FILE but not PATCHDIR.
# Work around that for now
DISTINFO_FILE=         ${.CURDIR}/distinfo

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake tar

# While earlier node is not known to fail, it seems straightforward to
# expect the current LTS or newer.
TOOL_DEPENDS+=	nodejs>=22:../../lang/nodejs22

EGDIR=			share/jitsi-meet
PKG_SYSCONFSUBDIR=	jitsi/meet
CONF_FILES=		${EGDIR}/config.js ${PKG_SYSCONFDIR}/config.js
CONF_FILES+=		${EGDIR}/interface_config.js \
			${PKG_SYSCONFDIR}/interface_config.js
CONF_FILES+=		${EGDIR}/title.html ${PKG_SYSCONFDIR}/title.html

# \todo Explain how this variable makes its way into the package.
BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS=	${EGDIR} share/examples/jitsi-meet share/doc/jitsi-meet

do-configure:
	cd ${WRKSRC} && \
		npm install

# Running webpack takes a lot of RAM.  Building on a machine with 6000
# MB with WRKDIR on tmpfs, heavy paging resulted, and it wasn't clear
# that it would finish.  With 10000 MB, it built in reasonable time
# with some paging.  With 12000 MB, it built without issues.
BUILD_TARGET=	compile

INSTALL_TARGET=	deploy source-package

post-install:
	${RUN} ${TAR} -C ${DESTDIR}${PREFIX}/share -xjf ${WRKSRC}/jitsi-meet.tar.bz2
	${INSTALL_DATA} ${WRKSRC}/config.js \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/config.js
	${INSTALL_DATA} ${WRKSRC}/interface_config.js \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/interface_config.js
	${INSTALL_DATA} ${WRKSRC}/title.html \
		${DESTDIR}${PREFIX}/share/examples/jitsi-meet/title.html
	${INSTALL_DATA} files/README.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/jitsi-meet/README.pkgsrc

.include "../../mk/bsd.pkg.mk"
