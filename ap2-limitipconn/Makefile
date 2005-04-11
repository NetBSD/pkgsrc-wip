# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:46 tvierling Exp $
#

DISTNAME=		mod_limitipconn-0.22
PKGNAME=		${DISTNAME:S/mod_/ap2-/}
CATEGORIES=		www
MASTER_SITES=		http://dominia.org/djao/limit/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://dominia.org/djao/limitipconn2.html
COMMENT=		Limits per-IP connections to an Apache 2 server


MAKE_FLAGS+=		APXS=${APXS:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_limitipconn
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_limitipconn/

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
