# $NetBSD: Makefile,v 1.3 2015/01/31 20:03:00 jihbed Exp $

DISTNAME=	cddlib-0.94j
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=cddlib/}
GITHUB_RELEASE=	0.94j

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cddlib/cddlib
COMMENT=	Efficient implementation of the Double Description Method
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	share/doc/cddlib

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cddlib
	${INSTALL_DATA} ${WRKSRC}/doc/cddlibman.pdf \
		${DESTDIR}${PREFIX}/share/doc/cddlib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
