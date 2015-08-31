# $NetBSD: Makefile,v 1.2 2015/08/31 19:13:30 yhardy Exp $

GITHUB_PROJECT=	termit
DISTNAME=	${GITHUB_TAG}
PKGNAME=	ruby-${GITHUB_PROJECT}-2.11.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pawurb/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=pawurb/termit/}
COMMENT=	Google Translate in your terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/termit-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

GEM_NAME=	termit-${PKGVERSION_NOREV}
GEM_SPECFILE=	termit.gemspec

DEPENDS+=	ruby-delegate_it-[0-9]*:../../wip/ruby-delegate_it

.include "../../lang/ruby/gem.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
