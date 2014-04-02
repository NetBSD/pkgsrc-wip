# $NetBSD: Makefile,v 1.5 2014/04/02 18:50:54 nros Exp $

DISTNAME=	qore-json-module-1.4
PKGREVISION=	2
CATEGORIES=	wip
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	JSON module for Qore
HOMEPAGE=       http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALL_TARGET=	install install-html-local

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore/license/modules/json
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore/license/modules/json
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore/license/modules/json

.include "../../wip/qore/module.mk"
.include "options.mk"

.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
