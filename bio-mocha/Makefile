# $NetBSD$

DISTNAME=	bio-mocha-1.20
CATEGORIES=	biology
MASTER_SITES=	https://software.broadinstitute.org/software/mocha/
MASTER_SITES+=	${MASTER_SITE_GITHUB:=samtools/}
DISTFILES+=	bio-mocha_1.20-20240505.tar.gz
GITHUB_PROJECT=	bcftools
GITHUB_TAG=	1.21

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://software.broadinstitute.org/software/mocha/
COMMENT=	Bcftools plugin for mosaic chromosomal alteration analysis
LICENSE=	mit

SUBST_CLASSES+=	1
SUBST_STAGE.1=	pre-configure
SUBST_SED.1+=	-e 's|@PV@|${PV}|g'
SUBST_FILES.1+=	${WRKSRC}/configure.ac

DEPENDS=	bash:../../shells/bash
DEPENDS+=	bcftools>=1.16:../../biology/bcftools

USE_TOOLS+=	autoconf automake autoreconf gmake perl pax
GNU_CONFIGURE=	yes
REPLACE_PERL=	misc/* test/test.pl

DATADIR=		${PREFIX}/share/bio-mocha
INSTALLATION_DIRS=	libexec/bcftools

post-extract:
	@${MV} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	@${MKDIR} ${WRKSRC}/MoCha
	@${MV} ${WRKDIR}/*.R ${WRKSRC}/MoCha

pre-configure:
	cd ${WRKSRC} && autoreconf -if

# One .so for each .c in the mocha distfile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/extendFMT.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mocha.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mochatools.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/trio-phase.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/MoCha && pax -rw . ${DESTDIR}${DATADIR})

.include "../../wip/htslib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
