# $NetBSD: Makefile,v 1.9 2014/02/22 18:51:30 nros Exp $

DISTNAME=	qore-0.8.8
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	Qore programming language
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake flex bison
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

PKGCONFIG_OVERRIDE+=	qore.pc.in

INSTALL_TARGET=         install install-html-local

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
