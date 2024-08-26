# $NetBSD$

GITHUB_PROJECT=	libSavitar
GITHUB_TAG=	4.13.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/libSavitar/
COMMENT=	C++ implementation of 3mf loading with SIP python bindings
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		sip
SUBST_STAGE.sip=	pre-configure
SUBST_MESSAGE.sip=	Rename py-sip name.
SUBST_FILES.sip=	cmake/FindSIP.cmake
SUBST_SED.sip=		-e 's|\(SIP_EXECUTABLE sip\)|\1${PYVERSSUFFIX}|'

PY_PATCHPLIST=YES

BUILDLINK_DEPMETHOD.py-sip4?=	build

.include "../../lang/python/extension.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../wip/py-sip4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
