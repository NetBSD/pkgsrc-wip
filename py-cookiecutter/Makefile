# $NetBSD: Makefile,v 1.3 2015/06/17 13:33:40 ahp-nils Exp $

DISTNAME=	cookiecutter-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/audreyr/cookiecutter/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.zip

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/audreyr/cookiecutter/
COMMENT=	Command-line utility that creates projects from project templates
LICENSE=	modified-bsd

USE_LANGUAGES=	#none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	34 33 27
USE_TOOLS+=	make:build
AUTO_MKDIRS=	yes
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.2.0:../../wip/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-click<4.0:../../devel/py-click
# for python < 3.0
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 30
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif


PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	cookiecutter/*.py

post-build:
	cd ${WRKSRC}/docs/ && make SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX} man

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/cookiecutter.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/


.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
