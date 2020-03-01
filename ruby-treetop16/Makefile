# $NetBSD$

DISTNAME=	treetop-1.6.10
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nathansobo/treetop
COMMENT=	Ruby-based text parsing and interpretation DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-polyglot>=0.3.1:../../devel/ruby-polyglot

CONFLICTS=		ruby[1-9][0-9]-treetop-[0-9]*
OVERRIDE_GEMSPEC+=	polyglot:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
