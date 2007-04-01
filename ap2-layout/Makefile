# $NetBSD: Makefile,v 1.3 2007/04/01 02:19:12 obache Exp $

DISTNAME=	mod_layout-4.1
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tangent.org/
COMMENT=	Apache2 module to wrap served pages with a header and/or footer

USE_LIBTOOL=	yes
APACHE_MODULE=	yes

MAKE_FLAGS+=	builddir=${WRKSRC:Q}
MAKE_ENV+=	APXS=${APXS:Q}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
