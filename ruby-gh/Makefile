# $NetBSD$

DISTNAME=	gh-0.15.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/travis-ci/gh
COMMENT=	Layerd GitHub API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable-[0-9]*:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-backports-[0-9]*:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.8:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=2.9:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-pipeline-[0-9]*:../../wip/ruby-net-http-pipeline

OVERRIDE_GEMSPEC+=	addressable>=2.4.0
OVERRIDE_GEMSPEC+=	faraday>=0.8
OVERRIDE_GEMSPEC+=	multi_json>=1.0
OVERRIDE_GEMSPEC+=	net-http-persistent>=2.9

#RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
