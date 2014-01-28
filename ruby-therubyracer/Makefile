# $NetBSD: Makefile,v 1.1 2014/01/28 15:59:49 fhajny Exp $

DISTNAME=	therubyracer-0.12.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	lang

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/cowboyd/libv8
COMMENT=	Embedded V8 Javascript
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-libv8>=3.16:../../wip/v8-316

USE_LANGUAGES+=	c c++

CONFIGURE_ARGS+=	--with-system-v8
CONFIGURE_ARGS+=	--with-v8-dir=${BUILDLINK_PREFIX.v8}

.include "../../wip/v8-316/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
