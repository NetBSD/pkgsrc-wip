# $NetBSD$

DISTNAME=	haplohseq-0.1.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_PROJECT=	haplohseq

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/integrativecancergenomics/software/haplohseq
COMMENT=	Identify regions of allelic imbalance
LICENSE=	mit

REPLACE_SH=	example/example_run.sh

SUBST_CLASSES+=		test
SUBST_STAGE.test=	pre-configure
SUBST_SED.test=		-e 's|\.\./haplohseq|haplohseq|'
SUBST_SED.test+=	-e 's|python|mkdir example_output; ${PYTHONBIN}|'
SUBST_FILES.test=	example/example_run.sh

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax
MAKE_FILE=	makefile

EXAMPLESDIR=	${PREFIX}/share/examples/haplohseq

INSTALLATION_DIRS=	share/examples/haplohseq

post-patch:
	${SED} -e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|" \
		${FILESDIR}/haplohseq-example.in > ${WRKDIR}/haplohseq-example

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/haplohseq-example ${DESTDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${RM} scripts/*.orig && pax -rw example ldmap scripts ${DESTDIR}${EXAMPLESDIR})

do-test:
	(cd ${WRKSRC}/build/test && ${SH} ${FILESDIR}/run-tests)

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
