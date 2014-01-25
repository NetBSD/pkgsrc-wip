# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:16 thomasklausner Exp $

DISTNAME=	cogent-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	 biology python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cogent/
EXTRACT_SUFX=	.tgz#md5=732d19ab6f4ded2a75a3ae77eaea9872

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/pycogent
COMMENT=	Cogent A toolkit for statistical analysis of biological sequences
LICENSE=		gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.5.6:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-pyrex

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} runtests.py )

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
