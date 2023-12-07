# $NetBSD$

DISTNAME=	python-nis-0.0.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=niclasr/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	python-nis
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/niclasr/python-nis/
COMMENT=	NIS python module
LICENSE=	python-software-foundation

USE_TOOLS+=	pkg-config

CMAKE_USE_GNU_INSTALL_DIRS=	no
PY_PATCHPLIST=			yes

.include "../../devel/cmake/build.mk"
.include "../../lang/python/extension.mk"
.if ${OPSYS} == "Linux"
.  if ${GLIBC_VERSION:C/[0-9]\.//g} > 31
.include "../../wip/libnsl/buildlink3.mk"
.  endif
.endif
.include "../../mk/bsd.pkg.mk"
