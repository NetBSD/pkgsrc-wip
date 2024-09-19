# $NetBSD$

DISTNAME=	gitlab-grit-2.8.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitlabhq/grit
COMMENT=	Object oriented read/write access to Git repositories via Ruby
LICENSE=	mit

DEPENDS+=	git-[0-9]*:../../devel/git
DEPENDS+=	${RUBY_PKGPREFIX}-charlock_holmes>=0.6<1:../../wip/ruby-charlock_holmes
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1<2:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-posix-spawn>=0.3<1:../../devel/ruby-posix-spawn

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
