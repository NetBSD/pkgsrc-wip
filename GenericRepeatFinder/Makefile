# $NetBSD$

DISTNAME=	GenericRepeatFinder-1.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=bioinfolabmu/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bioinfolabmu/GenericRepeatFinder/
COMMENT=	Detect repeated sequences in genomes
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_DIRS+=	src
USE_LANGUAGES=	c c++
MAKE_ENV+=	OPENMP_CFLAGS=${OPENMP_CFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# see https://mac.r-project.org/openmp/
OPENMP_CFLAGS=	-Xclang -fopenmp
LIBS+=		-lomp
.else
OPENMP_CFLAGS=	-fopenmp
.endif

INSTALLATION_DIRS+=	bin share/doc/GenericRepeatFinder

BIN_FILES+=	grf-alignment
BIN_FILES+=	grf-alignment2
BIN_FILES+=	grf-dbn
BIN_FILES+=	grf-filter
BIN_FILES+=	grf-intersperse
BIN_FILES+=	grf-main
BIN_FILES+=	grf-mite-cluster
BIN_FILES+=	grf-nest
BIN_FILES+=	ltr_finder

DOC_FILES+=	QuickGuideForReviewer.txt
DOC_FILES+=	readme.txt

do-install:
.for f in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${DESTDIR}${PREFIX}/bin/${f}
.endfor
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/GenericRepeatFinder/${f}
.endfor

.include "../../parallel/openmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
