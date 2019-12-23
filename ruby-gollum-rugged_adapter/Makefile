# $NetBSD$

DISTNAME=	gollum-rugged_adapter-0.4.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/rugged_adapter
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.15:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-rugged>=0.25<1:../../devel/ruby-rugged

.include "../../lang/ruby/gem.mk"
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
