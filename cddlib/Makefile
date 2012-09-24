# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cddlib-094f
PKGNAME=	cddlib-0.94
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.ifor.math.ethz.ch/pub/fukuda/cdd/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ifor.math.ethz.ch/~fukuda/cdd_home/
COMMENT=	Library for finding vertices of convex polytopes
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/doc/cddlib

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cddlib
	${INSTALL_DATA} ${WRKSRC}/doc/cddlibman.pdf \
		${DESTDIR}${PREFIX}/share/doc/cddlib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
