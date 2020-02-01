# $NetBSD$

DISTNAME=	roadie-4.0.0
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie/
COMMENT=	Making HTML emails comfortable for the Ruby rockstars
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-css-parser>=1.4<2:../../www/ruby-css-parser
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8<2:../../textproc/ruby-nokogiri

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
