# $NetBSD$

GITHUB_PROJECT=	Cura
GITHUB_TAG=	4.13.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/Cura/
COMMENT=	3D printer / slicing GUI built on top of the Uranium framework
LICENSE=	gnu-lgpl-v3

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk-[0-9]*:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-zeroconf-[0-9]*:../../net/py-zeroconf
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-trimesh-[0-9]*:../../wip/py-trimesh
DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	${PYPKGPREFIX}-backports.tarfile-[0-9]*:../../wip/py-backports.tarfile # from jaraco/context.py

REPLACE_PYTHON+=	cura_app.py

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	pre-configure
SUBST_MESSAGE.fix-version=	Fixing Cura version.
SUBST_FILES.fix-version=	CMakeLists.txt
SUBST_SED.fix-version=		-e "s,\(CURA_VERSION\) \"master\",\1 \"${GITHUB_TAG}\",g"

PYTHON_VERSIONS_ACCEPTED=	311 310

PY_PATCHPLIST=	YES

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/CuraEngine/buildlink3.mk"
.include "../../wip/fdm_materials/buildlink3.mk"
.include "../../wip/libSavitar/buildlink3.mk"
.include "../../wip/py-Uranium/buildlink3.mk"
.include "../../wip/py-pynest2d/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
