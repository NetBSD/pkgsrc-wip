# $NetBSD$

GITHUB_PROJECT=	panda
DISTNAME=	panda-2015.10
PKGNAME=	p6-${DISTNAME}
CATEGORIES=	wip perl6
MASTER_SITES=	${MASTER_SITE_GITHUB:=tadzik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tadzik/panda/
COMMENT=	Perl 6 package manager
LICENSE=	artistic

WRKSRC=		${WRKDIR}/panda-2015.10
USE_LANGUAGES=	# none

do-build:
	cd ${WRKSRC} && perl6 ./bootstrap.pl

.include "../../mk/bsd.pkg.mk"
