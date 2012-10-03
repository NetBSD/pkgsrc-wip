# $NetBSD: Makefile,v 1.5 2012/10/03 14:30:47 asau Exp $
#

DISTNAME=		mozplugger-1.5.2
CATEGORIES=		www
MASTER_SITES=		http://downloads.mozdev.org/mozplugger/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://mozplugger.mozdev.org/
COMMENT=		Mozilla plugin for launching external viewers

MAKE_ARGS+=		-DPKG_SYSCONFDIR=${PKG_SYSCONFDIR}
CONF_FILES+=		${PREFIX}/share/examples/mozplugger/mozpluggerrc ${PKG_SYSCONFDIR}/mozpluggerrc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mozplugger
	${INSTALL_DATA} ${WRKSRC}/mozpluggerrc ${DESTDIR}${PREFIX}/share/examples/mozplugger/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/mozilla/plugins
	${INSTALL_LIB} ${WRKSRC}/mozplugger.so ${DESTDIR}${PREFIX}/lib/mozilla/plugins/
	${INSTALL_PROGRAM} ${WRKSRC}/mozplugger-controller ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mozplugger-helper ${DESTDIR}${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
