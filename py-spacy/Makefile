# $NetBSD$

DISTNAME=	spaCy-v3.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
WRKSRC=	${WRKDIR}/${DISTNAME:S/v//1}

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/spaCy/
COMMENT=	Short description of the package
LICENSE=	mit

USE_TOOLS+=     gmake 


BUILD_DEPENDS+= ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

#.include "../../devel/py-setuptools/buildlink3.mk"
.include "../../wip/py-cymem/buildlink3.mk"
.include "../../wip/py-preshed/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
