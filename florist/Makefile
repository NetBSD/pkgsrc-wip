# $NetBSD: Makefile,v 1.4 2004/01/27 03:43:25 xtraeme Exp $
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
USE_GNU_TOOLS+=		make
GCC_SUBPREFIX=		gcc3

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
#.include "${LOCALBASE}/${GCC_SUBPREFIX}/mk/ada.mk"
