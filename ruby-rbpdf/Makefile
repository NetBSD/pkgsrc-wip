# $NetBSD$

DISTNAME=	rbpdf-1.20.1
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naitoh/rbpdf/
COMMENT=	Ruby on Rails TCPDF plugin
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-htmlentities-[0-9]*:../../wip/ruby-htmlentities
DEPENDS+=	${RUBY_PKGPREFIX}-rbpdf-font>=1.19.0<1.20:../../wip/ruby-rbpdf-font

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
