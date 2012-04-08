# $NetBSD: Makefile,v 1.11 2012/04/08 19:09:42 thomasklausner Exp $
#

# Created using instructions from:
# http://www.netbsd.org/docs/pkgsrc/creating.html

DISTNAME=		edoc-0.2.0
CATEGORIES=		devel
MASTER_SITES=		http://downloads.sourceforge.net/edoc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		brendon@christian.net
HOMEPAGE=		http://edoc.sourceforge.net/index.html
COMMENT=		Compile time C++ exception analysis/documentation tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_TOOLS+=		perl
USE_TOOLS+=		flex
USE_TOOLS+=		bison


# I dont think the build requires pkg-config. It just creates pkg-config data files.
# USE_TOOLS+=		pkg-config

# I am not sure if i specify ldd as a tool, as it is checked for in the configure script and used by the resulting binary. NOT by the build.
# USE_TOOLS+=		ldd

# Used by geneds.sh
USE_TOOLS+=		nm
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++


USE_PKGLOCALEDIR=	no
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDoc/EDoc.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDocBFD/EDocBFD.pc.in
GNU_CONFIGURE=		yes


# Some of the linux dependencies I may need to add.
# texinfo, libltdl3-dev

# Bring in libpython2.5 and the python interpreter.
.include "../../lang/python25/buildlink3.mk"
#.include "../../lang/python/pyversion.mk"

# Bring in libbfd.
.if !exists(/usr/include/bfd.h)
USE_BUILTIN.binutils=no
.endif
.include "../../devel/binutils/buildlink3.mk"

# Bring in libltdl
.include "../../devel/libltdl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
