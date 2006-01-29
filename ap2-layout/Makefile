# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 15:25:19 obache Exp $

DISTNAME=	mod_layout-4.0.2a
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://tangent.org/
COMMENT=	Apache2 module to wrap served pages with a header and/or footer

USE_LIBTOOL=	yes
APACHE_MODULE=	yes

MAKE_FLAGS+=	builddir=${WRKSRC:Q}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
