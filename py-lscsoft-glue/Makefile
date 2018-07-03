# $NetBSD: Makefile,v 1.5 2017/09/17 13:35:03 adam Exp $

DISTNAME=	lscsoft-glue-1.56.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lscsoft-glue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lsc-group.phys.uwm.edu/daswg/projects/glue.html
COMMENT=	Grid LSC User Environment
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-m2crypto-[0-9]*:../../security/py-m2crypto

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-m2crypto

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
