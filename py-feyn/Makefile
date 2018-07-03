# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:18 thomasklausner Exp $

DISTNAME=	pyfeyn-0.3.2
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.hepforge.org/archive/pyfeyn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/pyfeyn/
COMMENT=	Easy-to-use Python library to help physicists draw Feynman diagrams
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.3.2
PYTHON_VERSIONED_DEPENDENCIES=	X

post-extract:
	${MV} ${WRKSRC}/mkfeyndiag ${WRKSRC}/mkfeyndiag${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
