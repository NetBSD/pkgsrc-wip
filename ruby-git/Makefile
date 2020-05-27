# $NetBSD: Makefile,v 1.4 2013/09/09 14:05:31 thomasklausner Exp $

DISTNAME=	git-1.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/schacon/ruby-git
COMMENT=	Manipulate Git repositories by wrapping around the git binary
LICENSE=	mit

DEPENDS+=	git-base>=1.6:../../devel/git-base

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
