# $NetBSD$

GITHUB_PROJECT=	xml-writer
GITHUB_TAG=	4d30a9d
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=masak/}

MAINTAINER=	mspo@NetBSD.org
HOMEPAGE=	https://github.com/masak/xml-writer
COMMENT=	A Perl 6 module to generate XML
LICENSE=	artistic

WRKSRC=	${WRKDIR}/${DISTNAME}*
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;

do-build:
	cd ${WRKSRC} && mkdir -p ${DESTDIR}${PREFIX}/share/perl6/site
	cd ${WRKSRC} && ${PREFIX}/bin/perl6 ${PREFIX}/share/perl6/bin/install-dist.pl -for=site -to=${DESTDIR}${PREFIX}/share/perl6/site

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
