# $NetBSD: Makefile,v 1.5 2008/09/06 20:54:43 thomasklausner Exp $

DISTNAME=	mod_layout-4.1
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	2
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
