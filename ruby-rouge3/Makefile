# $NetBSD$

DISTNAME=	rouge-3.30.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rouge/rouge3/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rouge.jneen.net/
COMMENT=	Pure-ruby colorizer based on pygments
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	:files bin/rougify=
OVERRIDE_GEMSPEC+=	:executables rougify=rougify3

pre-build:
	cd ${WRKSRC}/bin && ${MV} rougify rougify3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
