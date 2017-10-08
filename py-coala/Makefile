# $NetBSD$

GITHUB_PROJECT=	coala
DISTNAME=	coala-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=coala/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://coala.io/
COMMENT=	Unified command-line interface for linting and fixing all your code
LICENSE=	gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=   27

INSTALLATION_DIRS+=	${PKGMANDIR}

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-print-[0-9]*:../../wip/py-print
DEPENDS+=	${PYPKGPREFIX}-coala_utils-[0-9]*:../../wip/py-coala_utils
DEPENDS+=	${PYPKGPREFIX}-colorlog-[0-9]*:../../wip/py-colorlog
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-unidiff-[0-9]*:../../wip/py-unidiff
DEPENDS+=	${PYPKGPREFIX}-libclang-py3-[0-9]*:../../wip/py-libclang-py3
DEPENDS+=	${PYPKGPREFIX}-dependency_management-[0-9]*:../../wip/py-dependency_management

post-install:
.for w in coala coala-ci coala-delete-orig coala-format coala-json
	${RUN} ${MV} ${DESTDIR}${PREFIX}/bin/${w} \
		${DESTDIR}${PREFIX}/bin/${w}${PYVERSSUFFIX}
.endfor
	${RUN} ${MV} ${DESTDIR}${PREFIX}/coala.1 \
		 ${DESTDIR}${PREFIX}/${PKGMANDIR}/coala.1

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
