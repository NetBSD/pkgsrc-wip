# $NetBSD$

DISTNAME=	hg-git-devel-1.0.2.20231002
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
HG_REPO=	https://foss.heptapod.net/mercurial/hg-git
HG_TAG=		162f2ee771d94b19293372bce43ff28c91a02ad1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.7:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	hg_git

.include "../../lang/python/egg.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
