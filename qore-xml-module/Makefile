# $NetBSD: Makefile,v 1.5 2014/04/03 10:52:40 nros Exp $

DISTNAME=	qore-xml-module-1.2
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	XML module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore/license/modules/xml
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore/license/modules/xml
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore/license/modules/xml


.include "../../wip/qore/module.mk"
.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
