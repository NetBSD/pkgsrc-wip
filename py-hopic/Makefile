# $NetBSD$

DISTNAME=	hopic-1.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hopic/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/tomtom-international/hopic
COMMENT=	Generic jenkins shared pipeline alternative
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm_git_archive:../../devel/py-setuptools_scm_git_archive
DEPENDS+=	${PYPKGPREFIX}-click>=7.0<8.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-commisery>=0.5<1:../../wip/py-commisery
DEPENDS+=	${PYPKGPREFIX}-git>=3<4:../../wip/py-git
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata<3.8:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-dateutil:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-yaml:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-stemming>=1<2:../../wip/py-stemming
DEPENDS+=	${PYPKGPREFIX}-regex:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-typeguard>=2.10<3:../../wip/py-typeguard

WRKSRC=		${WRKDIR}/hopic-${PKGVERSION}
USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} hopic hopic-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
