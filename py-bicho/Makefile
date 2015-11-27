# $NetBSD$

DISTNAME=	bicho_0.9
PKGNAME=	${PYPKGPREFIX}-bicho-0.9
CATEGORIES=	devel
MASTER_SITES=	https://github.com/downloads/MetricsGrimoire/Bicho/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MetricsGrimoire/Bicho
COMMENT=	Bug tracking system tool analyzer
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/bicho-0.9

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/bicho ${WRKSRC}/bin/bicho${PYVERSSUFFIX}


.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
