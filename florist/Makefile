# $NetBSD: Makefile,v 1.1.1.1 2003/12/11 22:02:05 johnrshannon Exp $
#

DISTNAME=		florist-3.15p-src
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
EXTRACT_SUFX=		.tgz

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
COMMENT=		FSU implementation of POSIX.5 (Ada binding)

BUILD_DEPENDS+=		gcc3-ada-[0-9]*:../../lang/gcc3-ada

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_AUTOCONF=		yes
AUTOCONF_REQD=		2.12
USE_GMAKE=		yes
CC=${LOCALBASE}/gcc3/bin/cc
CPP=${LOCALBASE}/gcc3/bin/cpp
CXX=${LOCALBASE}/gcc3/bin/cxx
GCC=${LOCALBASE}/gcc3/bin/gcc
MAKE_ENV+=ADAC=${LOCALBASE}/gcc3/bin/gcc
MAKE_ENV+=ADA_INCLUDE_PATH+=${GCC_ARCHDIR}/adainclude

post-extract:
	${CP} ${FILESDIR}/pconfig.NetBSD ${WRKSRC}/configs

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

do-install:
	@${MKDIR} ${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/*.ad[sb] \
		${WRKSRC}/floristlib/*.ali \
		${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/libflorist.a ${PREFIX}/lib

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
