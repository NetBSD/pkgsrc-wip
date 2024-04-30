# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:18 thomasklausner Exp $

DISTNAME=	pyfeyn-1.0.0
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	graphics
MASTER_SITES=	http://www.hepforge.org/archive/pyfeyn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/pyfeyn/
COMMENT=	Easy-to-use Python library to help physicists draw Feynman diagrams
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-X-[0-9]*:../../textproc/py-X

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mkfeyndiag ${DESTDIR}${PREFIX}/bin/mkfeyndiag-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
