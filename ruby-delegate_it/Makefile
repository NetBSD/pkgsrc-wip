# $NetBSD: Makefile,v 1.1 2015/08/26 15:30:34 yhardy Exp $

GITHUB_PROJECT=	delegate_it
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pawurb/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pawurb/delegate_it/
COMMENT=	ActiveSupport like "delegate" method for non Rails projects
LICENSE=	mit

WRKSRC=		${WRKDIR}/delegate_it-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

GEM_NAME=	delegate_it-${PKGVERSION_NOREV}
GEM_SPECFILE=	delegate_it.gemspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
