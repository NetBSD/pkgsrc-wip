# $NetBSD$

GITHUB_PROJECT=	Pod-To-HTML
GITHUB_TAG=	c5847eab0a1b7c39133c1ef7c93fc80b8a0cd792
PKGREVISION=	1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=perl6/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/jnthn/${GITHUB_PROJECT}
COMMENT=	convert POD6 to HTML
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

DEPENDS+=	p6-uri-[a-z0-9]*:../p6-uri

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
