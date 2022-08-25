# $NetBSD: Makefile,v 1.3 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	opencascade-7.6.3
CATEGORIES=	cad
PKGREVISION=	1

GIT_REPO=		https://git.dev.opencascade.org/repos/occt.git
GIT_TAG=		V${PKGVERSION_NOREV:S/./_/g}
GIT_EXTRACTDIR.default=	${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}

# Official webpage requires login
# MASTER_SITES=	https://sources.archlinux.org/other/community/opencascade/
# Download URL may have changed? Eg.
# https://dev.opencascade.org/system/files/occt/OCC_7.6.0_release/opencascade-7.6.0.tgz
# EXTRACT_SUFX=	.tgz

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	http://www.opencascade.org/
COMMENT=	Software development platform for 3D CAD CAM CAE
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	bash
USE_LANGUAGES=	c c++

REPLACE_BASH+=	adm/templates/*
REPLACE_BASH+=	*

CHECK_PORTABILITY_SKIP+=	samples/qt/*

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
# Required for proper alloca(3) support on NetBSD
BUILDLINK_TRANSFORM+=		opt:-std=c++0x:-std=gnu++11
LDFLAGS+=			-lexecinfo
CMAKE_ARGS=			-DINSTALL_DIR_SCRIPT=${DISTNAME}.script

# HACK
post-install:
	${RUN} chmod go-w ${DESTDIR}${PREFIX}/bin/*
	${RUN} rm -f ${DESTDIR}${PREFIX}/share/opencascade/resources/DrawResources/InitEnvironment.tcl.orig

SUBST_CLASSES+=			cmakebinletter
SUBST_STAGE.cmakebinletter=	post-install
SUBST_MESSAGE.cmakebinletter=	Fixing $$OCCT_INSTALL_BIN_LETTER in cmake files
SUBST_FILES.cmakebinletter=	${DESTDIR}${PREFIX}/lib/cmake/opencascade/*.cmake
SUBST_SED.cmakebinletter=	-e 's/\\$${OCCT_INSTALL_BIN_LETTER}//g'

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
