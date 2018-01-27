# $NetBSD: Makefile,v 1.3 2014/09/08 10:25:33 fhajny Exp $

DISTNAME=	therubyracer-0.12.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	lang

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/cowboyd/libv8
COMMENT=	Embedded V8 Javascript
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-libv8>=3.16:../../wip/ruby-libv8
DEPENDS+=	${RUBY_PKGPREFIX}-ref-[0-9]*:../../devel/ruby-ref

USE_LANGUAGES+=	c c++

CONFIGURE_ARGS+=	--with-system-v8
CONFIGURE_ARGS+=	--with-v8-dir=${BUILDLINK_PREFIX.v8}

.include "../../wip/v8-316/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
