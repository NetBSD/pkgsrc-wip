# $NetBSD$
#

DISTNAME=	biostar-tools
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Meta-package for Biostar Handbook tools

WWW=            https://www.biostarhandbook.com

LICENSE=        BSD2CLAUSE

# For a current list see http://data.biostarhandbook.com/install/conda.txt.
# Also included are some programs not listed above, but mentioned in the text.
# TODO: Add hdfview

DEPENDS+=	fastq-trim>0:../../wip/fastq-trim
DEPENDS+=	fastqc>0:../../biology/fastqc
DEPENDS+=	biolibc-tools>0:../../wip/biolibc-tools
DEPENDS+=	gffread>0:../../biology/gffread
DEPENDS+=	kallisto>0:../../biology/kallisto
DEPENDS+=	hisat2>0:../../biology/hisat2
DEPENDS+=	samtools>0:../../biology/samtools
DEPENDS+=	igv>0:../../biology/igv
DEPENDS+=	${PYPKGPREFIX}-multiqc-[0-9]*:../../wip/py-multiqc
DEPENDS+=	wget>0:../../net/wget
DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	lz4>0:../../archivers/lz4
DEPENDS+=	xz>0:../../archivers/xz
DEPENDS+=	zstd>0:../../archivers/zstd
DEPENDS+=	nano>0:../../editors/nano
DEPENDS+=	parallel>0:../../parallel/parallel
DEPENDS+=	csvkit>0:../../textproc/csvkit
DEPENDS+=	miller>0:../../textproc/miller
DEPENDS+=	bwa>0:../../biology/bwa
DEPENDS+=	bowtie2>0:../../biology/bowtie2
DEPENDS+=	bedtools>0:../../biology/bedtools
DEPENDS+=	bamtools>0:../../wip/bamtools
DEPENDS+=	${PYPKGPREFIX}-cutadapt-[0-9]*:../../biology/py-cutadapt
DEPENDS+=	seqtk>0:../../biology/seqtk
DEPENDS+=	datamash>0:../../wip/datamash
DEPENDS+=	bcftools>0:../../biology/bcftools
DEPENDS+=	subread>0:../../wip/subread
DEPENDS+=	Trimmomatic>0:../../biology/trimmomatic
DEPENDS+=	ncbi-blast+>0:../../biology/ncbi-blast+
DEPENDS+=	cdhit>0:../../biology/cdhit
DEPENDS+=	${PYPKGPREFIX}-biopython-[0-9]*:../../biology/py-biopython
# DEPENDS+=	>0:../../

# Allow pkg build on non-amd64 systems until sra-tools supports them
.if ${MACHINE_ARCH} == amd64 || ${MACHINE_ARCH} == aarch64
DEPENDS+=   sra-tools>0:../../biology/sra-tools
.endif

META_PACKAGE=	yes

# Fetch fails, permission denied
# DEPENDS+=	readseq>0:../../wip/readseq
# Build fails, need simde?
# DEPENDS+=	minimap2>0:../../biology/minimap2
# Build fails (Darwin)
# DEPENDS+=	${PYPKGPREFIX}-pysam-[0-9]*:../../wip/py-pysam
# Fetch fails, needs update
# DEPENDS+=	freebayes>0:../../wip/freebayes

# FreeBSD port depends:
#                 seqkit>0:biology/seqkit \
#                 csvtk>0:science/csvtk \
#                 ncbi-entrez-direct>0:biology/ncbi-entrez-direct \
#                 snpeff>0:biology/snpeff \
#                 picard-tools>0:biology/picard-tools \
#                 bbmap>0:biology/bbmap \
#                 emboss>0:biology/emboss \
#                 picard-tools>0:biology/picard-tools \
#                 p5-Net-SSLeay>0:security/p5-Net-SSLeay \
#                 bioawk>0:biology/bioawk \
#                 vt>0:biology/vt \
#                 ${PYTHON_PKGNAMEPREFIX}crossmap>0:biology/py-crossmap@${PY_FLAVOR} \
#                 ${PYTHON_PKGNAMEPREFIX}goatools>0:biology/py-goatools@${PY_FLAVOR} \
#                 erminej>0:biology/erminej \
#                 ${PYTHON_PKGNAMEPREFIX}ont-fast5-api>0:biology/py-ont-fast5-api@${PY_FLAVOR} \
#                 flash>0:biology/flash \
#                 bfc:biology/bfc \
#                 Jellyfish>0:biology/jellyfish \
#                 mafft>0:biology/mafft \
#                 clustal-omega>0:biology/clustal-omega \
#                 ${PYTHON_PKGNAMEPREFIX}pywgsim>0:biology/py-pywgsim@${PY_FLAVOR} \
#                 sam2pairwise>0:biology/sam2pairwise \
#                 bamutil>0:biology/bamutil \
#                 ${PYTHON_PKGNAMEPREFIX}deepTools>0:biology/py-deeptools@${PY_FLAVOR} \

# do-install:
# 	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
# 	${INSTALL_SCRIPT} ${WRKDIR}/biostar-shell ${STAGEDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
