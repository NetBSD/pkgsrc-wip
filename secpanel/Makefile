# $NetBSD: Makefile,v 1.2 2005/04/11 21:15:33 tvierling Exp $
#

DISTNAME=		secpanel-0.4.3
CATEGORIES=		security x11
MASTER_SITES=		http://www.pingx.net/secpanel/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.pingx.net/secpanel/
COMMENT=		GUI front-end for SSH

NO_BUILD=		# defined

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
