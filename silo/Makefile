# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:48 thomasklausner Exp $
#

VER=		4.10.2
DISTNAME=	silo-${VER}-bsd
PKGNAME=	${DISTNAME:S/-bsd//}
CATEGORIES=	math
MASTER_SITES=	https://wci.llnl.gov/content/assets/docs/simulation/computer-codes/silo/silo-${VER}/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wci.llnl.gov/codes/silo/
COMMENT=	Mesh and filed I/O library and scientific databases
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran77
USE_LIBTOOL=	yes

# pkgsrc is not currently able to fetch distfiles from https web servers
# (see mk/fetch/fetch.mk), so you have to use a browser for now.
FETCH_BEFORE_ARGS=	--no-check-certificate
CONFIGURE_ARGS+=	--with-qt
#CONFIGURE_ARGS+=	--with-hdf5=${BUILDLINK_PREFIX.hdf5}/lib
#CONFIGURE_ARGS+=	--with-hdf5=${BUILDLINK_PREFIX.hdf5}/include

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-readline=no
.else
.include "../../devel/readline/buildlink3.mk"
.endif

#.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
