# $NetBSD$

GITHUB_PROJECT=	oo-monitors
GITHUB_TAG=	b9de07c277f0a9fa805bb18113788228f6acfd3b
PKGREVISION= 1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jnthn/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/jnthn/oo-monitors/
COMMENT=	A monitor provides per-instance mutual exclusion for objects
LICENSE=	artistic

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

DEPENDS+=	p6-xml-writer:../p6-xml-writer

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
