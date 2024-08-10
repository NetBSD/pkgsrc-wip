# $NetBSD$

DISTNAME=	sinatra-contrib-4.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra-contrib/sinatra-contrib4/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra4:../../wip/ruby-sinatra4
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=3.0<4:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection4-4.0.0:../../wip/ruby-rack-protection4
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
