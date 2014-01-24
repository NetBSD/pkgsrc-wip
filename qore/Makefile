# $NetBSD: Makefile,v 1.5 2014/01/24 21:13:25 nros Exp $

DISTNAME=	qore-0.8.8
CATEGORIES=	lang

.include	"../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Qore programming language
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake flex bison
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

PKGCONFIG_OVERRIDE+=	qore.pc.in
CONFIGURE_ARGS+= 	--with-doxygen=no

#NetBSD 6 and lower has an stdio.h that breaks this package
#NOT_FOR_PLATFORM=       NetBSD-[0-6]*-*

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=	share/qore/license
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.GPL ${DESTDIR}${PREFIX}/share/qore/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL ${DESTDIR}${PREFIX}/share/qore/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT ${DESTDIR}${PREFIX}/share/qore/license
	${INSTALL_DATA} ${WRKSRC}/README-LICENSE ${DESTDIR}${PREFIX}/share/qore/license

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
