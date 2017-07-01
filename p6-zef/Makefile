# $NetBSD$

GITHUB_PROJECT=	zef
GITHUB_TAG=	v0.1.19
DISTNAME=	zef-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=ugexe/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/ugexe/zef/
COMMENT=	Perl 6 module manager
LICENSE=	artistic

WRKSRC=		${WRKDIR}/zef-0.1.19
USE_LANGUAGES=	# none

ZEF=		${PREFIX}/bin/perl6 -I${WRKSRC}/lib ${WRKSRC}/bin/zef

do-build:
	cd ${WRKSRC} && ${ZEF} build .

do-install:
	cd ${WRKSRC} && ${ZEF} -v install --install-to=inst#${DESTDIR}${PREFIX} .
	${RM} -f ${DESTDIR}${PREFIX}/precomp/.lock

.include "../../wip/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
