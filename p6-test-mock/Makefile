# $NetBSD$

GITHUB_PROJECT=	test-mock
GITHUB_TAG=	b28dd4f3410ff1298649ea3ccb4efac0f77ab71b
PKGREVISION= 1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jnthn/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/jnthn
COMMENT=	A Perl 6 module for testing
LICENSE=	artistic

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

DEPENDS+=	p6-oo-monitors-[a-z0-9]*:../p6-oo-monitors

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
