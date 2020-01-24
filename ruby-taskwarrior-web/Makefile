# $NetBSD$

DISTNAME=	taskwarrior-web-1.1.12
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://theunraveler.github.io/taskwarrior-web/
COMMENT=	Lightweight web interface for Taskwarrior
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport32>=3.2.0:../../devel/ruby-activesupport32
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.8.0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-parseconfig>=1.0.7:../../devel/ruby-parseconfig
DEPENDS+=	${RUBY_PKGPREFIX}-rack-flash3>=1.0.0:../../wip/ruby-rack-flash3
DEPENDS+=	${RUBY_PKGPREFIX}-rinku:../../wip/ruby-rinku
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0.0:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra-simple-navigation:../../wip/ruby-sinatra-simple-navigation
DEPENDS+=	${RUBY_PKGPREFIX}-vegas:../../wip/ruby-vegas
DEPENDS+=	${RUBY_PKGPREFIX}-versionomy:../../wip/ruby-versionomy
DEPENDS+=	taskwarrior-[0-9]*:../../time/taskwarrior

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
