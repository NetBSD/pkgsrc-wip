# $NetBSD: Makefile,v 1.2 2015/06/10 13:43:17 ahp-nils Exp $

DISTNAME=	slowhttptest-1.7
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=shekyan/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/shekyan/slowhttptest
COMMENT=	Tool implementing some Slow HTTP attacks
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
