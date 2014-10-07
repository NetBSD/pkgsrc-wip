# $NetBSD: Makefile,v 1.5 2014/10/07 14:18:53 nros Exp $

DISTNAME=	qore-uuid-module-1.3
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	UUID module for Qore
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

#This is needed in order to comply the with MIT license and binary distribution
licensedir=		share/doc/${PKGBASE}/license
INSTALLATION_DIRS+=	${licensedir}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/${licensedir}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/${licensedir}

.include "options.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
