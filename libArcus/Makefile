# $NetBSD$

GITHUB_PROJECT=	libArcus
GITHUB_TAG=	4.13.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/libArcus/
COMMENT=	Creating a socket in a thread and using this socket to messages
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		sip
SUBST_STAGE.sip=	pre-configure
SUBST_MESSAGE.sip=	Rename py-sip name.
SUBST_FILES.sip=	cmake/FindSIP.cmake
SUBST_SED.sip=		-e 's|\(SIP_EXECUTABLE sip\)|\1${PYVERSSUFFIX}|'

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-install
SUBST_MESSAGE.fix-prefix=	Fix prefix.
SUBST_FILES.fix-prefix=		CMakeFiles/Export/lib/cmake/Arcus/Arcus-targets.cmake
SUBST_SED.fix-prefix=		-e 's|${WRKDIR}/.buildlink|${PREFIX}|g'

PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
