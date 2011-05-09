# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:18:03 jihbed Exp $
#

DISTNAME=	cubature-20101018
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/cubature/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ab-initio.mit.edu/cubature/
COMMENT=	Multi-dimensional integration
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS= include	share/doc/cubature

do-install:
	${INSTALL_DATA} ${WRKSRC}/cubature.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cubature

.include "../../mk/bsd.pkg.mk"
