# $NetBSD: Makefile,v 1.11 2014/06/22 19:57:10 thomasklausner Exp $

DISTNAME=	mod_layout-4.1
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tangent.org/362/mod_layout.html
COMMENT=	Apache2 module to wrap served pages with a header and/or footer
LICENSE=	apache-2.0

USE_LIBTOOL=	yes
APACHE_MODULE=	yes

MAKE_FLAGS+=	builddir=${WRKSRC:Q}
MAKE_FLAGS+=	APXS=${APXS:Q}

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${BUILDLINK_PREFIX.apache}/share/httpd/build/instdso.sh \
		SH_LIBTOOL=${BUILDLINK_PREFIX.apache}/share/httpd/build/libtool \
		${WRKSRC}/mod_layout.la \
		${DESTDIR}${PREFIX}/lib/httpd

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
