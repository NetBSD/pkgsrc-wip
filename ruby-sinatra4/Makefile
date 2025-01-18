# $NetBSD$

DISTNAME=	sinatra-4.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra/sinatra4/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} <= 32
DEPENDS+=	${RUBY_PKGPREFIX}-logger>=1.6.0:../../wip/ruby-logger
.endif
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0<4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection4-4.1.1:../../wip/ruby-rack-protection4
DEPENDS+=	${RUBY_PKGPREFIX}-rack-session>=2.0.0<3:../../www/ruby-rack-session
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=3.0<4:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
