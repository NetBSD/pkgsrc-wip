# $NetBSD$

DISTNAME=	rinku-2.0.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vmg/rinku
COMMENT=	Drop-in replacement for Rails 'auto_link'
LICENSE=	mit

# minitest now included in ruby-base
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.0.0:../../devel/ruby-minitest
DEPENDS+=	${RUBY_PKGPREFIX}-base:../../lang/${RUBY_PKGPREFIX}-base
DEPENDS+=	${RUBY_PKGPREFIX}-rake-compiler:../../wip/ruby-rake-compiler

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
