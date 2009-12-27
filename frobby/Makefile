# $NetBSD: Makefile,v 1.1.1.1 2009/12/27 20:57:50 jihbed Exp $
#

DISTNAME=	frobby_v0.8.2
PKGNAME=	frobby-0.8.2
CATEGORIES=	math
MASTER_SITES=	http://www.broune.com/frobby/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.broune.com/frobby/index.html
COMMENT=	Computations with monomial ideals
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/frobby \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
