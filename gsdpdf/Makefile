# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:25:06 jihbed Exp $
#

DISTNAME=	gs2009code
PKGNAME=	gsdpdf-2009
CATEGORIES=	physics
MASTER_SITES=	http://projects.hepforge.org/gsdpdf/code/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/gsdpdf
COMMENT=	Gaunt-Stirling double Parton Distribution Functions
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	lib  share/doc/gsdpdf

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gsdpdf
	${INSTALL_DATA} ${WRKSRC}/gsdpdf.f ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gsalps.f ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
