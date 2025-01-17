# $NetBSD: Makefile,v 1.11 2023/08/14 05:23:52 wiz Exp $

DISTNAME=	stacks-2.68
CATEGORIES=	biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://catchenlab.life.illinois.edu/stacks/
COMMENT=	Software pipeline for building loci from short-read sequences
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++14
# Is this needed?
# FORCE_CXX_STD=	c++14
USE_TOOLS+=		bash perl:run
GNU_CONFIGURE=		yes

REPLACE_BASH+=		scripts/stacks-count-reads-per-sample-per-locus
REPLACE_BASH+=		scripts/stacks-gdb
REPLACE_BASH+=		scripts/stacks-samtools-tview
REPLACE_PERL=		scripts/*.pl
REPLACE_PYTHON+=	scripts/*.py
REPLACE_PYTHON+=	scripts/stacks-dist-extract
REPLACE_PYTHON+=	scripts/stacks-integrate-alignments
REPLACE_PYTHON+=	scripts/stacks-private-alleles

ERROR: [check-interpreter.mk] The interpreter "/usr/bin/env" of "/home/bacon/Pkgsrc/pkgsrc/wip/stacks/work/.destdir/home/bacon/Pkgsrc/pkg/bin/stacks-private-alleles" is not allowed.

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	scripts/stacks-hist2d-loci-samples-coverage

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
# pkgsrc sed wrapper lacks -i
SUBST_CLASSES+=		sed
SUBST_STAGE.sed=	pre-configure
SUBST_FILES.sed=	Makefile.in
SUBST_SED.sed=		-e 's|sed -i.bkp|/usr/bin/sed -i .bkp|'
CFLAGS+=		-Xpreprocessor -fopenmp

.include "../../parallel/openmp/buildlink3.mk"
.else
# macOS clang lacks OpenMP
CFLAGS+=		-fopenmp
.endif

LDFLAGS.SunOS+=		-lsocket

.include "../../lang/python/application.mk"
.include "../../math/R/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
