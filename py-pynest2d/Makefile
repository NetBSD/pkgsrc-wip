# $NetBSD$

GITHUB_PROJECT=	pynest2d
GITHUB_TAG=	4.12.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/pynest2d/
COMMENT=	Python bindings for libnest2d
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		sip
SUBST_STAGE.sip=	pre-configure
SUBST_MESSAGE.sip=	Rename py-sip name.
SUBST_FILES.sip=	cmake/FindSIP.cmake
SUBST_SED.sip=		-e 's|\(SIP_EXECUTABLE sip\)|\1${PYVERSSUFFIX}|'

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		cmake/FindClipper.cmake
SUBST_FILES.fix-paths+=		cmake/FindNLopt.cmake
SUBST_SED.fix-paths=		-e "s,@prefix@,${PREFIX},g"

PY_PATCHPLIST=YES
.include "../../lang/python/extension.mk"
.include "../../wip/libnest2d-ultimaker/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
