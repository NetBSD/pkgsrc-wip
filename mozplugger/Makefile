# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:06 tvierling Exp $
#

DISTNAME=		mozplugger-1.5.2
CATEGORIES=		www
MASTER_SITES=		http://downloads.mozdev.org/mozplugger/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://mozplugger.mozdev.org/
COMMENT=		Mozilla plugin for launching external viewers

USE_X11=		yes
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

.include "../../mk/bsd.pkg.mk"
