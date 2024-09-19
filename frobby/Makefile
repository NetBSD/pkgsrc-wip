# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:49 asau Exp $
#

DISTNAME=	frobby_v0.8.2
PKGNAME=	frobby-0.8.2
CATEGORIES=	math
MASTER_SITES=	http://www.broune.com/frobby/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.broune.com/frobby/index.html
COMMENT=	Computations with monomial ideals
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/frobby \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
