# $NetBSD: Makefile,v 1.1.1.1 2010/02/24 10:05:59 jihbed Exp $
#

DISTNAME=	cddlib-094f
PKGNAME=	cddlib-0.94
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.ifor.math.ethz.ch/pub/fukuda/cdd/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ifor.math.ethz.ch/~fukuda/cdd_home/
COMMENT=	Library for finding vertices of convex polytopes
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/doc/cddlib

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cddlib
	${INSTALL_DATA} ${WRKSRC}/doc/cddlibman.pdf \
		${DESTDIR}${PREFIX}/share/doc/cddlib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
