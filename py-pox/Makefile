# $NetBSD$

DISTNAME=	pox-0.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/1a/0c/ec447fb0ed88bc1c09bf0dadf00e40ea05fda17e841d15bb351a52d9e192/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/pox
COMMENT=	Utilities for filesystem exploration and automated builds
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/pox ${WRKSRC}/scripts/pox${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
