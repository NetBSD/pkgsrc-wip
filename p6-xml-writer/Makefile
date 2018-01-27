# $NetBSD$

GITHUB_PROJECT=	xml-writer
GITHUB_TAG=	4d30a9d8e06033ca97387971b653817becd5a759
PKGREVISION=	2
DISTNAME=	p6-${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=masak/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/masak/xml-writer
COMMENT=	A Perl 6 module to generate XML
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar
NO_INTALL=	yes

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site

do-install:
	cd ${WRKSRC} && RAKUDO_RERESOLVE_DEPENDENCIES=0 ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
