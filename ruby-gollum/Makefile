# $NetBSD$

DISTNAME=	gollum-6.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/gollum
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gollum-lib>=6.0<7:../../wip/ruby-gollum-lib
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.3<3:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.1.0<1.2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0<4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rackup>=2.1<3:../../www/ruby-rackup
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra4>=4.0<5:../../wip/ruby-sinatra4
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra-contrib4>=4.0<5:../../wip/ruby-sinatra-contrib4
DEPENDS+=	${RUBY_PKGPREFIX}-mustache-sinatra>=2.0<3:../../wip/ruby-mustache-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-useragent>=0.16.2<0.17:../../wip/ruby-useragent
DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=4.1<5:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-octicons>=19.0<20:../../wip/ruby-octicons
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=4.1<5:../../misc/ruby-sprockets
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets-helpers>=1.2<2:../../wip/ruby-sprockets-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-rss>=0.3<1:../../wip/ruby-rss
DEPENDS+=	${RUBY_PKGPREFIX}-therubyrhino>=2.1.0<2.2.0:../../wip/ruby-therubyrhino
DEPENDS+=	${RUBY_PKGPREFIX}-webrick>=1.7<2:../../www/ruby-webrick
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.8<2:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
