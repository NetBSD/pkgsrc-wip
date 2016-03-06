# $NetBSD$

GITHUB_PROJECT=	panda
DISTNAME=	panda-2015.12
PKGNAME=	p6-${DISTNAME}
CATEGORIES=	wip perl6
MASTER_SITES=	${MASTER_SITE_GITHUB:=tadzik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tadzik/panda/
COMMENT=	Perl 6 package manager
LICENSE=	artistic

WRKSRC=		${WRKDIR}/panda-2015.12
USE_LANGUAGES=	# none

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && perl6 ./bootstrap.pl --prefix=${DESTDIR}${PREFIX}
	rm -rf ${DESTDIR}${PREFIX}/lib/.precomp ${DESTDIR}${PREFIX}/bin/*.bat

.include "../../mk/bsd.pkg.mk"
