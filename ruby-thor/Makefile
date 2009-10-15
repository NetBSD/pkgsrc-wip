# $NetBSD: Makefile,v 1.1.1.1 2009/10/15 10:09:09 fhajny Exp $

DISTNAME=	thor-0.11.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/wycats/thor
COMMENT=	Scripting framework that replaces rake and sake
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
