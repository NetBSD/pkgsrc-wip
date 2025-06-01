# $NetBSD$

DISTNAME=	v3.10.0.rc3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=dl1ksv/}
GITHUB_PROJECT=	gr-funcube
GITHUB_TAG=	refs/tags/v3.10.0.rc3
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dl1ksv/gr-funcube/
COMMENT=	GNU Radio Funcube driver
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/gr-funcube-3.10.0.rc3
USE_LANGUAGES=	c++

# cmake files in odd place are not found
DEPENDS+=	${PYPKGPREFIX}-pybind11-[0-9]*:../../devel/py-pybind11

.include	"../../devel/cmake/build.mk"

.include        "../../devel/boost-headers/buildlink3.mk"
.include        "../../devel/boost-libs/buildlink3.mk"
.include        "../../devel/libusb1/buildlink3.mk"
.include        "../../lang/python/application.mk"
.include        "../../lang/python/pyversion.mk"
.include	"../../ham/gnuradio-core/buildlink3.mk"
.include	"../../ham/gnuradio-uhd/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
