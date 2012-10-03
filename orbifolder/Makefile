# $NetBSD: Makefile,v 1.2 2012/10/03 21:32:47 asau Exp $
#

DISTNAME=	orbifolder-1.2
CATEGORIES=	physics
MASTER_SITES=	http://orbifolder.hepforge.org/source/V1.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://orbifolder.hepforge.org/
COMMENT=	Study the Low Energy Effective Theory of Heterotic Orbifolds
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/orbifolder/orbifolder ${DESTDIR}${PREFIX}/bin

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
