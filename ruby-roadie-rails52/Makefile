# $NetBSD$

DISTNAME=	roadie-rails-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails/rails52/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie-rails/
COMMENT=	Hooks Roadie into your Rails application to help with email generation
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-railties52-[0-9]*:../../devel/ruby-railties52
DEPENDS+=	${RUBY_PKGPREFIX}-roadie>=3.1<5.0:../../wip/ruby-roadie

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
