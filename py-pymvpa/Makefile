# $NetBSD: Makefile,v 1.1.1.1 2011/03/23 09:48:20 jihbed Exp $
#

DISTNAME=	pymvpa_0.4.5
PKGNAME=	${PYPKGPREFIX}-mvpa-0.4.5
CATEGORIES=	biology
MASTER_SITES=	https://alioth.debian.org/frs/download.php/3358/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.pymvpa.org/
COMMENT=	Multivariate pattern analysis
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-psyco-[0-9]*:../../lang/py-psyco
DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pymvpa-0.4.5

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
