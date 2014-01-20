# $NetBSD: Makefile,v 1.1 2014/01/20 19:23:27 nros Exp $

DISTNAME=	qore-yaml-module-0.4
CATEGORIES=	textproc

.include "../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Yaml module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PTHREAD_OPTS+=	require
CONFIGURE_ARGS+=--with-doxygen=no

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=	share/qore-yaml-module/license
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL ${DESTDIR}${PREFIX}/share/qore-yaml-module/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT ${DESTDIR}${PREFIX}/share/qore-yaml-module/license

.include "../../wip/qore/options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
