# $NetBSD: Makefile,v 1.1.1.1 2009/11/10 16:31:24 fhajny Exp $

DISTNAME=	git-1.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/schacon/ruby-git
COMMENT=	Manipulate Git repositories by wrapping around the git binary
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scmgit-base>=1.6:../../devel/scmgit-base

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
