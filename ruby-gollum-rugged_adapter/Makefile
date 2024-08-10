# $NetBSD$

DISTNAME=	gollum-rugged_adapter-3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gollum/rugged_adapter
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.4<4:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-rugged>=1.5<2:../../devel/ruby-rugged

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
