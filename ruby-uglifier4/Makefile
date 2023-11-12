# $NetBSD$

DISTNAME=	uglifier-4.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/uglifier/uglifier4/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lautis/uglifier
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0.3.0<3:../../lang/ruby-execjs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
