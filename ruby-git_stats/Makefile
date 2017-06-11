# $NetBSD$

GITHUB_PROJECT=	git_stats
DISTNAME=	git_status-1.0.14
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tomgi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomgi/git_stats/
COMMENT=	Git repository statistics generator
LICENSE=	mit

USE_GCC_RUNTIME=	yes

GEM_NAME=	git_stats-${PKGVERSION_NOREV}
GEM_SPECFILE=	git_stats.gemspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
