# $NetBSD$

DISTNAME=	sprockets-3.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sprockets/sprockets3/}
CATEGORIES=	misc www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2.4<3:../../www/ruby-rack2
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	:files bin/sprockets=
OVERRIDE_GEMSPEC+=	:executables sprockets=sprockets3

pre-build:
	cd ${WRKSRC}/bin && ${MV} sprockets sprockets3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
