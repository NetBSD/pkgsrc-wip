# $NetBSD$

DISTNAME=	gollum-4.1.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/gollum
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=3.2<4:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-gollum-lib>=4.2.10<4.3:../../wip/ruby-gollum-lib
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown1>=1.9.0<1.10:../../wip/ruby-kramdown1
DEPENDS+=	${RUBY_PKGPREFIX}-mustache0>=0.99.5<1:../../wip/ruby-mustache0
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra1>=1.4.4<2:../../wip/ruby-sinatra1
DEPENDS+=	${RUBY_PKGPREFIX}-useragent>=0.16.2<0.17:../../wip/ruby-useragent

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
