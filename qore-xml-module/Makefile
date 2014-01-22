# $NetBSD: Makefile,v 1.2 2014/01/22 22:16:15 nros Exp $

DISTNAME=	qore-xml-module-1.2
CATEGORIES=	textproc

.include "../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XML module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore-xml-module/license
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore-xml-module/license
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore-xml-module/license


.include "../../wip/qore/plist-version.mk"
.include "../../wip/qore/options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
