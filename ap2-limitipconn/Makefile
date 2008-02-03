# $NetBSD: Makefile,v 1.8 2008/02/03 15:06:24 tnn2 Exp $
#

DISTNAME=		mod_limitipconn-0.22
PKGNAME=		${DISTNAME:S/mod_/ap2-/}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://dominia.org/djao/limit/

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://dominia.org/djao/limitipconn2.html
COMMENT=		Limits per-IP connections to an Apache 2 server

APACHE_MODULE=		yes
MAKE_FLAGS+=		APXS=${APXS:Q}
USE_LIBTOOL=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_limitipconn
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_limitipconn/

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
