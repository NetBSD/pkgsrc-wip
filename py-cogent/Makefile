# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:46 thomasklausner Exp $

DISTNAME=	cogent-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogent/}
EXTRACT_SUFX=	.tgz#md5=732d19ab6f4ded2a75a3ae77eaea9872

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/pycogent
COMMENT=	Cogent A toolkit for statistical analysis of biological sequences
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.5.6:../../databases/py-sqlalchemy

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-pyrex

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
