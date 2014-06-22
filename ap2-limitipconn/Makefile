# $NetBSD: Makefile,v 1.12 2014/06/22 19:57:10 thomasklausner Exp $
#

DISTNAME=		mod_limitipconn-0.22
PKGNAME=		${DISTNAME:S/mod_/ap2-/}
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		http://dominia.org/djao/limit/

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://dominia.org/djao/limitipconn2.html
COMMENT=		Limits per-IP connections to an Apache 2 server

PKG_DESTDIR_SUPPORT=	none

APACHE_MODULE=		yes
MAKE_FLAGS+=		APXS=${APXS:Q}
USE_LIBTOOL=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_limitipconn
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_limitipconn/

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
