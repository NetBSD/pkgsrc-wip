# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:12 othyro Exp $
#

DISTNAME=	orbifolder-1.2
CATEGORIES=	misc
MASTER_SITES=	http://orbifolder.hepforge.org/source/V1.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://orbifolder.hepforge.org/
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
