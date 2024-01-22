# $NetBSD$

DISTNAME=	gollum-5.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/gollum
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-gollum-lib>=5.2.2<6:../../wip/ruby-gollum-lib
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.3<3:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.1.0<1.2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra2>=2.0<3:../../wip/ruby-sinatra2
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra-contrib2>=2.0<3:../../wip/ruby-sinatra-contrib2
DEPENDS+=	${RUBY_PKGPREFIX}-mustache-sinatra>=2.0<3:../../wip/ruby-mustache-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-useragent>=0.16.2<0.17:../../wip/ruby-useragent
DEPENDS+=	${RUBY_PKGPREFIX}-gemojione>=4.1<5:../../wip/ruby-gemojione
DEPENDS+=	${RUBY_PKGPREFIX}-octicons>=12.0<13:../../wip/ruby-octicons
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets3>=3.7<4:../../wip/ruby-sprockets3
DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.5<4:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-uglifier4>=4.2<5:../../wip/ruby-uglifier4
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets-helpers>=1.2<2:../../wip/ruby-sprockets-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-therubyrhino>=2.1.0<2.2.0:../../wip/ruby-therubyrhino
DEPENDS+=	${RUBY_PKGPREFIX}-webrick>=1.7<2:../../www/ruby-webrick
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.8<2:../../devel/ruby-i18n

OVERRIDE_GEMSPEC+=	rss>=0.2.9

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
