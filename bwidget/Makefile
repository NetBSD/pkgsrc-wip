# $NetBSD: Makefile,v 1.6 2006/08/25 11:01:01 minskim Exp $
#

DISTNAME=		BWidget-1.6.0
PKGNAME=		${DISTNAME:S/BW/bw/}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		High-level widget set for Tcl/Tk

NO_BUILD=		yes
USE_TOOLS+=		wish:run

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bwidget \
		${PREFIX}/share/doc/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	cd ${WRKSRC} && \
	${PAX} -rwp e lang ${PREFIX}/lib/bwidget && \
	${PAX} -rwp e images ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* \
		${PREFIX}/share/doc/bwidget

.include "../../mk/bsd.pkg.mk"
