# $NetBSD: Makefile,v 1.6 2004/02/27 11:01:20 johnrshannon Exp $
#

DISTNAME=		florist-3.15p-src
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
EXTRACT_SUFX=		.tgz

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
COMMENT=		FSU implementation of POSIX.5 (Ada binding)

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_AUTOCONF=		yes
AUTOCONF_REQD=		2.12
USE_GNU_TOOLS+=		make
GCC_REQUIRED+=	3.3

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

.include "../../lang/gcc3-ada/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
