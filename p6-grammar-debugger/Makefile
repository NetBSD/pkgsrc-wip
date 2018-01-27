# $NetBSD$

GITHUB_PROJECT=	grammar-debugger
GITHUB_TAG=	443d53950288798610cf8878454cb8441c6ea84d
PKGREVISION=	1
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jnthn/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/jnthn/${GITHUB_PROJECT}
COMMENT=	A Perl 6 module for debugging grammars
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

DEPENDS+=	p6-Terminal-ANSIColor-[a-z0-1]*:../p6-Terminal-ANSIColor

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
