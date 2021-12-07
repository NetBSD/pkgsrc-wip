# $NetBSD$

DISTNAME=	pact_broker-client-1.58.0
CATEGORIES=	devel

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/pact-foundation/pact_broker-client/
COMMENT=	Client for the Pact Broker
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-httparty>=0.18.1:../../wip/ruby-httparty
DEPENDS+=	${RUBY_PKGPREFIX}-term-ansicolor>1.7:../../devel/ruby-term-ansicolor
DEPENDS+=	${RUBY_PKGPREFIX}-table_print>1.5:../../wip/ruby-table_print
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.20<2.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-dig_rb>1.0:../../wip/ruby-dig_rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
