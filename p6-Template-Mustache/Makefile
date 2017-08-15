# $NetBSD$

GITHUB_PROJECT=	p6-Template-Mustache
GITHUB_TAG=	2ffcb06e5417aadcfd3e3f663fdb2e738a165dfb
PKGREVISION= 1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=softmoth/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/softmoth/${GITHUB_PROJECT}
COMMENT=	Perl6 library for the Mustache template format
LICENSE=	artistic

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
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
