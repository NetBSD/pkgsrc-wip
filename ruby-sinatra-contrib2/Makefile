# $NetBSD$

DISTNAME=	sinatra-contrib-2.2.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra-contrib/sinatra-contrib2/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra2-2.2.4:../../wip/ruby-sinatra2
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann2>=2.0<3:../../wip/ruby-mustermann2
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection2-2.2.4:../../wip/ruby-rack-protection2
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
