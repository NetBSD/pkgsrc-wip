# $NetBSD: Makefile,v 1.8 2010/06/02 06:59:16 obache Exp $

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
MAKE_ENV+=	APXS=${APXS:Q}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
