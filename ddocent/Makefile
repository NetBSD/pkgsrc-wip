# $NetBSD$

DISTNAME=	dDocent-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpuritz/}
GITHUB_PROJECT=	dDocent
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ddocent.com/
COMMENT=	Bash pipeline for RAD sequencing
LICENSE=	mit

# bedtools version: https://github.com/jpuritz/dDocent/issues/15
# New ddocent works with 2.23.0 or >= 2.26.0
# Do we really need trimadap?  It used to be part of seqtk.
# ddocent test data do not unpack with FreeBSD 11.1 /usr/bin/unzip
DEPENDS=	mawk>=0:../../lang/mawk
DEPENDS+=	gawk>=0:../../lang/gawk
DEPENDS+=	coreutils>=0:../../sysutils/coreutils
DEPENDS+=	gnuplot>=0:../../graphics/gnuplot
DEPENDS+=	parallel>=0:../../parallel/parallel
DEPENDS+=	bwa>=0.7.13:../../biology/bwa
DEPENDS+=	cdhit>=0:../../biology/cdhit
DEPENDS+=	samtools>=1.3:../../biology/samtools
DEPENDS+=	vcftools>=0.1.15:../../wip/vcftools
DEPENDS+=	Trimmomatic>=0:../../biology/trimmomatic
DEPENDS+=	stacks>=0:../../biology/stacks
DEPENDS+=	rainbow>=0:../../wip/rainbow
DEPENDS+=	trimadap>=0:../../wip/trimadap
DEPENDS+=	seqtk>=0:../../wip/seqtk
DEPENDS+=	bedtools>=2.26.0:../../biology/bedtools
DEPENDS+=	pear-merger>=0:../../wip/pear-merger
DEPENDS+=	freebayes>=0:../../wip/freebayes

## These follow patch-dDocent, so don't apply them within the source tree,
## or they'll get picked up by patch generators and hard-code PREFIX
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-install
SUBST_SED.prefix+=	-e 's|%%PREFIX%%|${PREFIX}|g'
SUBST_SED.prefix+=	-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g'
SUBST_SED.prefix+=	-e 's|python|${PYTHONBIN}|g'
SUBST_FILES.prefix+=	${DESTDIR}${PREFIX}/bin/dDocent

USE_LANGUAGES=	# none
REPLACE_BASH=	dDocent *.sh
REPLACE_BASH+=	scripts/ddocent-assembly-test* scripts/*.sh scripts/dDocent_filters
REPLACE_PERL=	scripts/*.pl
REPLACE_PYTHON=	scripts/*.py
NO_BUILD=	yes
USE_TOOLS=	bash perl unzip

ERROR: [check-interpreter.mk] The interpreter "/usr/bin/env" of "/usr/pkgsrc/wip/ddocent/work/.destdir/usr/pkg/bin/ddocent-test" is not allowed.

PORTVERSION=	2.5.2
JAVAJARDIR=	${PREFIX}/lib/java

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/ddocent-assembly-test ${FILESDIR}/ddocent-assembly-test-cleanup \
		${WRKSRC}/scripts

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/dDocent \
		${WRKSRC}/*.sh \
		${WRKSRC}/scripts/ddocent-assembly-test \
		${WRKSRC}/scripts/ddocent-assembly-test-cleanup \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${WRKSRC}/scripts/dDocent_filters \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/python/tool.mk"
.include "../../wip/vcflib/buildlink3.mk"
.include "../../wip/bamtools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
