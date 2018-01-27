# $NetBSD$

GITHUB_PROJECT=	svg-plot
GITHUB_TAG=	f867cbfe31fd3aadb5830f2acd433c2d8a1de6df
PKGREVISION=	1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=moritz/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/moritz/svg-plot
COMMENT=	A simple 2D chart plotter for Perl 6
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

DEPENDS+=	p6-svg-[a-z0-9]*:../p6-svg

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
