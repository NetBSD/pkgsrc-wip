# $NetBSD: Makefile,v 1.3 2014/04/05 19:49:34 nros Exp $

DISTNAME=	qore-ssh2-module-0.9.9
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	SSH2 module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/qore/license/modules/ssh2
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/qore/license/modules/ssh2
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/qore/license/modules/ssh2

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
