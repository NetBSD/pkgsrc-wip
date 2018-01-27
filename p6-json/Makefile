# $NetBSD$

GITHUB_PROJECT=	json
GITHUB_TAG=	f6fe07850504e06a9422adb246e4326251004ad8
PKGREVISION=	1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=moritz/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/moritz/${GITHUB_PROJECT}
COMMENT=	A tiny JSON parser and emitter for Perl 6 on Rakudo
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
