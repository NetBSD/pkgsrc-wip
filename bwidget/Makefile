# $NetBSD: Makefile,v 1.3 2004/05/07 01:57:49 xtraeme Exp $
#

DISTNAME=		BWidget-1.6.0
PKGNAME=		${DISTNAME:S/BW/bw/}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		High-level widget set for Tcl/Tk

USE_BUILDLINK3=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bwidget \
		${PREFIX}/share/doc/html/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/bwidget
	cd ${WRKSRC} && \
	${PAX} -rwp e lang ${PREFIX}/lib/bwidget && \
	${PAX} -rwp e images ${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/BWman/*.htm* \
		${PREFIX}/share/doc/html/bwidget

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
