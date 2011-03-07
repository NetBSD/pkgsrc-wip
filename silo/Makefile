# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 12:20:06 jihbed Exp $
#

DISTNAME=	silo-4.8-bsd
PKGNAME=	${DISTNAME:S/-bsd//}
CATEGORIES=	science
MASTER_SITES=	https://wci.llnl.gov/codes/silo/silo-4.8/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wci.llnl.gov/codes/silo/silo-4.8/
COMMENT=	Mesh and filed I/O library and scientific databases
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran77

# pkgsrc is not currently able to fetch distfiles from https web servers
# (see mk/fetch/fetch.mk), so you have to use a browser for now.
FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate


CONFIGURE_ARGS+=	--with-readline
#CONFIGURE_ARGS+=	--with-hdf5=${BUILDLINK_PREFIX.hdf5}/lib
#CONFIGURE_ARGS+=	--with-hdf5=${BUILDLINK_PREFIX.hdf5}/include
CONFIGURE_ARGS+=	--with-qt

#.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
