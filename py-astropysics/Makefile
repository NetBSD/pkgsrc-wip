# $NetBSD: Makefile,v 1.2 2010/06/14 10:45:46 jihbed Exp $
#

DISTNAME=	Astropysics-0.1.dev-r596.tar
PKGNAME=	${PYPKGPREFIX}-astropysics-0.1
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/A/Astropysics/
EXTRACT_SUFX=	.gz#md5=15cb8e36b433ba6660c67939d234c6af

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.physics.uci.edu/~etolleru/software.html#astropysics
COMMENT=	Astrophysics libraries for Python
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Astropysics-0.1.dev-r596
USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
