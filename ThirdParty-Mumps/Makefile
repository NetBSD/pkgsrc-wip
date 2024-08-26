# $NetBSD$

DISTNAME=	3.0.7
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=coin-or-tools/}
GITHUB_PROJECT=	ThirdParty-Mumps
GITHUB_TAG=	refs/tags/releases/3.0.7
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coin-or-tools/ThirdParty-Mumps/
COMMENT=	COIN-OR autotools harness to build Mumps
LICENSE=	epl-v1.0

WRKSRC=		${WRKDIR}/ThirdParty-Mumps-releases-3.0.7
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config wget tar patch
USE_LANGUAGES=	c fortran

PKGCONFIG_OVERRIDE+=	coinmumps.pc.in

MUMPS_MASTER_SITE=	http://coin-or-tools.github.io/ThirdParty-Mumps
MUMPS_VERSION=		MUMPS_5.7.2
MUMPS_DISTFILE=		${MUMPS_VERSION}.tar.gz

# TODO: The MUMPS_DISTFILE needs to be in distinfo, extracted automatically
# FreeBSD port math/coin-or-mumps creates a soft link to auto-extracted file. How to do that in pkgsrc?
# Change USE_TOOLS accordingly
post-extract:
	cd ${WRKSRC} && wget --no-check-certificate ${MUMPS_MASTER_SITE}/${MUMPS_DISTFILE} && tar xvzf ${MUMPS_DISTFILE} && ${LN} -s ${MUMPS_VERSION} MUMPS

post-patch: # patching from get.Mumps
	cd ${WRKSRC} && \
		patch -p0 < mumps_mpi.patch && \
		${MV} MUMPS/libseq/mpi.h MUMPS/libseq/mumps_mpi.h

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
