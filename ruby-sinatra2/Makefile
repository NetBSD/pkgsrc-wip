# $NetBSD$

DISTNAME=	sinatra-2.2.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra/sinatra2/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2<3:../../www/ruby-rack2
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection2-2.2.4:../../wip/ruby-rack-protection2
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann2>=2.0<3:../../wip/ruby-mustermann2
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
