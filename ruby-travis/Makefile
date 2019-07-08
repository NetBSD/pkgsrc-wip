# $NetBSD$

DISTNAME=	travis-1.8.10
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/travis-ci/travis.rb
COMMENT=	Travis CI Client (CLI and Ruby library)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.9:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-faraday_middleware>=0.9.1:../../www/ruby-faraday_middleware
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-backports-[0-9]*:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.1:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-gh>=0.13:../../wip/ruby-gh
DEPENDS+=	${RUBY_PKGPREFIX}-typhoeus>=0.6.8:../../wip/ruby-typhoeus
DEPENDS+=	${RUBY_PKGPREFIX}-pusher-client>=0.4:../../wip/ruby-pusher-client

OVERRIDE_GEMSPEC+=	faraday>=0.9
OVERRIDE_GEMSPEC+=	faraday_middleware>=0.9.1
OVERRIDE_GEMSPEC+=	highline>=1.6
OVERRIDE_GEMSPEC+=	launchy>=2.1
OVERRIDE_GEMSPEC+=	gh>=0.13
OVERRIDE_GEMSPEC+=	typhoeus>=0.6.8
OVERRIDE_GEMSPEC+=	pusher-client>=0.4

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
