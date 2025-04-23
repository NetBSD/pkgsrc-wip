# $NetBSD: Makefile,v 1.24 2023/08/14 05:24:02 wiz Exp $

DISTNAME=	RBTools-5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=reviewboard/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.reviewboard.org/docs/rbtools/dev/
COMMENT=	Tool to submit patches to a Review Board
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-certifi>=2023.5.7:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
#DEPENDS+=	${PYPKGPREFIX}-housekeeping>=1.1:../../devel/py-housekeeping
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-puremagic>=0:../../sysutils/py-puremagic
#DEPENDS+=	${PYPKGPREFIX}-pydiffx>=1.1.0:../../devel/py-pydiffx
#DEPENDS+=	${PYPKGPREFIX}-texttable>=0:../../devel/py-texttable
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-tqdm>=0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=5.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.9:../../devel/py-importlib-resources
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0:../../devel/py-test-env
# kgb

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		rbtools/testing/scripts/editor.py

WRKSRC=		${WRKDIR}/rbtools-release-${PKGVERSION_NOREV}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
