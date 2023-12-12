# $NetBSD$

DISTNAME=	hexdump-3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hexdump/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/techtonik/hexdump/
COMMENT=	Dump binary data to hex format and restore from there
LICENSE=	public-domain

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} hexdump.py --test

# test data only
post-install:
	${RM} ${DESTDIR}${PREFIX}/data/hexfile.bin

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
