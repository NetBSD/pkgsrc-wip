# $NetBSD$

DISTNAME=	actionpack-xml_parser-2.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/actionpack/actionpack52/}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	XML parameters parser for Action Pack (removed from core in Rails 4.0)
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack52-[0-9]*:../../www/ruby-actionpack52
DEPENDS+=	${RUBY_PKGPREFIX}-railties52-[0-9]*:../../devel/ruby-railties52

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
