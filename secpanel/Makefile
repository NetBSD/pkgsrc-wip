# $NetBSD: Makefile,v 1.4 2005/10/14 00:38:14 dhowland Exp $
#

DISTNAME=		secpanel-0.5.1
CATEGORIES=		security x11
MASTER_SITES=		http://www.pingx.net/secpanel/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.pingx.net/secpanel/
COMMENT=		GUI front-end for SSH

NO_BUILD=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/secpanel
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/*.tcl ${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/default.* ${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/secpanel.* ${PREFIX}/lib/secpanel/
	${INSTALL_DATA_DIR} ${PREFIX}/lib/secpanel/images
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/images/*.gif ${PREFIX}/lib/secpanel/images/
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
