# $NetBSD$

DISTNAME=	textX-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textX/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://textx.github.io/textX/
COMMENT=	Domain-Specific Languages and parsers in Python made easy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twine>=1.13.0:../../net/py-twine
DEPENDS+	${PYPKGPREFIX}-arpeggio>=1.10.1:../../wip/py-arpeggio
TEST_DEPEND= ${PYPKGPREFIX}-flake8>=:../../devel/py-flake8

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
