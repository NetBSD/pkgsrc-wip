# $NetBSD: Makefile,v 1.1 2014/01/20 20:56:04 nros Exp $

DISTNAME=	qore-json-module-1.4
CATEGORIES=	wip

.include "../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	JSON module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore-json-module/license
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore-json-module/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore-json-module/license

.include "../../wip/qore/options.mk"

.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
