# $NetBSD$

DISTNAME=	rack-protection-4.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack-protection/rack-protection4/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0<4:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
