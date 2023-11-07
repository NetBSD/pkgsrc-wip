# $NetBSD$

DISTNAME=	rack-protection-2.2.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack-protection/rack-protection2/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2:../../www/ruby-rack2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
