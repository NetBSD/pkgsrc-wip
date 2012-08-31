# $NetBSD: Makefile,v 1.1 2012/08/31 18:21:50 jihbed Exp $
#

DISTNAME=	orbifolder-1.2
CATEGORIES=	physics
MASTER_SITES=	http://orbifolder.hepforge.org/source/V1.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://orbifolder.hepforge.org/
COMMENT=	Study the Low Energy Effective Theory of Heterotic Orbifolds
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/orbifolder/orbifolder ${DESTDIR}${PREFIX}/bin

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
