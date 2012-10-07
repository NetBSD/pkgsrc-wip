# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:44 asau Exp $

DISTNAME=	git-1.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/schacon/ruby-git
COMMENT=	Manipulate Git repositories by wrapping around the git binary
LICENSE=	mit

DEPENDS+=	scmgit-base>=1.6:../../devel/scmgit-base

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
