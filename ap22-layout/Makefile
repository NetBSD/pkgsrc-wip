# $NetBSD: Makefile,v 1.1.1.1 2010/06/02 08:38:53 obache Exp $

DISTNAME=	mod_layout-5.1
PKGNAME=	${DISTNAME:S/mod_/ap22-/}
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tangent.org/362/mod_layout.html
COMMENT=	Apache22 module to wrap served pages with a header and/or footer
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../www/apache22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
