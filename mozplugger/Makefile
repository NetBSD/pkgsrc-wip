# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:23 kristerw Exp $
#

DISTNAME=		mozplugger-1.5.2
CATEGORIES=		www
MASTER_SITES=		http://downloads.mozdev.org/mozplugger/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://mozplugger.mozdev.org/
COMMENT=		Mozilla plugin for launching external viewers

MAKE_ARGS+=		-DPKG_SYSCONFDIR=${PKG_SYSCONFDIR}
USE_PKGINSTALL=		yes
CONF_FILES+=		${PREFIX}/share/examples/mozplugger/mozpluggerrc ${PKG_SYSCONFDIR}/mozpluggerrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mozplugger
	${INSTALL_DATA} ${WRKSRC}/mozpluggerrc ${PREFIX}/share/examples/mozplugger/
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mozilla/plugins
	${INSTALL_LIB} ${WRKSRC}/mozplugger.so ${PREFIX}/lib/mozilla/plugins/
	${INSTALL_PROGRAM} ${WRKSRC}/mozplugger-controller ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mozplugger-helper ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
