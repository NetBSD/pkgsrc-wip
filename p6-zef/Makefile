# $NetBSD$

GITHUB_PROJECT=	zef
GITHUB_TAG=	v0.4.6
DISTNAME=	zef-${GITHUB_TAG:S/v//}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=ugexe/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/ugexe/zef/
COMMENT=	Perl 6 module manager
LICENSE=	artistic

USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar
NO_BUILD=	yes

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;
CHECK_INTERPRETER_SKIP+=	share/perl6/site/bin/zef-j

ZEF=		${PREFIX}/bin/perl6 -I${WRKSRC}/lib ${WRKSRC}/bin/zef

do-install:
	cd ${WRKSRC} && ${ZEF} --debug install .
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/site/precomp/.lock
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/site/version
	cd ${DESTDIR}${PREFIX} && mkdir bin && ${LN} -sf ../share/perl6/site/bin/zef bin/zef

.include "../../lang/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
