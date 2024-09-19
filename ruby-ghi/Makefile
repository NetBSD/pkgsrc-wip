# $NetBSD$
#

DISTNAME=	ghi-1.2.0
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_RUBYGEMS}
EXTRACT_SUFX=	.gem

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stephencelis/ghi
COMMENT=	GitHub Issues on the command line
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pygments.rb-[0-9]*:../../www/ruby-pygments.rb

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
