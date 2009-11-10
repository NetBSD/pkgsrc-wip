# $NetBSD: Makefile,v 1.2 2009/11/10 17:15:03 fhajny Exp $

DISTNAME=	treetop-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://treetop.rubyforge.org/
COMMENT=	Ruby-based parsing DSL based on parsing expression grammars
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-polyglot>=0.2.5:../../wip/ruby-polyglot

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
