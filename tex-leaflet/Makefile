# $NetBSD: Makefile,v 1.1.1.1 2008/10/26 13:18:15 leot1990 Exp $
#

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-1.0c
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/leaflet/
COMMENT=	Create small handouts (flyers)

USE_DIRS+=	texmf-1.2

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex leaflet.ins

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/leaflet
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/leaflet.pdf \
		${WRKSRC}/leaflet-manual.pdf ${PKG_LOCALTEXMFPREFIX}/doc/latex/leaflet
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/leaflet
	${INSTALL_DATA} ${WRKSRC}/leaflet.cls \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/leaflet

.include "../../mk/bsd.pkg.mk"
