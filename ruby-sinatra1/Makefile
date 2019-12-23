# $NetBSD: Makefile,v 1.27 2019/02/06 14:54:35 taca Exp $

DISTNAME=	sinatra-1.4.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra/sinatra1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.5<2:../../www/ruby-rack16
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection1>=1.4<2:../../wip/ruby-rack-protection1
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3<3:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
