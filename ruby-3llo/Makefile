# $NetBSD$

DISTNAME=	3llo-1.1.0
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/qcam/3llo
COMMENT=	CLI for Trello
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.12.0:../../devel/ruby-tty-prompt

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
