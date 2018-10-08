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

WRKSRC=		${WRKDIR}/zef-0.4.6
USE_LANGUAGES=	# none
USE_TOOLS+=	gtar
EXTRACT_USING=	gtar

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} * -type f -print |${SORT} -u;
CHECK_INTERPRETER_SKIP+=	share/perl6/site/bin/zef-j

ZEF=		${PREFIX}/bin/perl6 -I${WRKSRC}/lib ${WRKSRC}/bin/zef

do-build:
	echo "Build of ZEF no longer needed skipping"
#	cd ${WRKSRC} && ${ZEF} build . --debug

do-install:
	cd ${WRKSRC} && perl6 -I. bin/zef install .
	#cd ${WRKSRC} && ${ZEF} --to='inst#${DESTDIR}${PREFIX}/share/perl6/site' --force --debug install .
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/site/precomp/.lock
	#${RM} -f ${DESTDIR}${PREFIX}/share/perl6/site/repo.lock
	${RM} -f ${DESTDIR}${PREFIX}/share/perl6/site/version
	cd ${DESTDIR}${PREFIX} && mkdir bin && ${LN} -fs ../share/perl6/site/bin/zef bin/zef

.include "../../lang/rakudo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
