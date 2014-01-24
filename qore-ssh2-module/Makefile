# $NetBSD: Makefile,v 1.1 2014/01/24 20:02:37 nros Exp $

DISTNAME=	qore-ssh2-module-0.9.9
CATEGORIES=	security

.include "../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SSH2 module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore-ssh2-module/license
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore-ssh2-module/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore-ssh2-module/license

.include "../../wip/qore/options.mk"

.include "../../devel/pcre/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
