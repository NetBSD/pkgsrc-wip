# $NetBSD: Makefile,v 1.3 2015/09/13 20:13:47 yhardy Exp $

GITHUB_PROJECT=	termit
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-3.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pawurb/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pawurb/termit/
COMMENT=	Google Translate in your terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/termit-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

GEM_NAME=	termit-${PKGVERSION_NOREV}
GEM_SPECFILE=	termit.gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-delegate_it-[0-9]*:../../wip/ruby-delegate_it
DEPENDS+=	${RUBY_PKGPREFIX}-rest-client-[0-9]*:../../www/ruby-rest-client

.include "../../lang/ruby/gem.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
