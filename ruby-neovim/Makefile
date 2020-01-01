# $NetBSD$

DISTNAME=	neovim-0.8.1
CATEGORIES=	devel editors

HOMEPAGE=	https://github.com/neovim/neovim-ruby
COMMENT=	Ruby client to Neovim
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-msgpack>=1.0.0:../../devel/ruby-msgpack

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
