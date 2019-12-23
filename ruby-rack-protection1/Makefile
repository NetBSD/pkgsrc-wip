# $NetBSD: Makefile,v 1.14 2018/09/23 17:06:28 taca Exp $

DISTNAME=	rack-protection-1.5.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rack-protection/rack-protection1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sinatrarb.com/protection/
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=0:../../www/ruby-rack16

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
