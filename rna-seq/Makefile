# $NetBSD$
#

DISTNAME=	rna-seq-1.0
CATEGORIES=	meta-pkgs biology
MASTER_SITES=	# empty

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Core tools needed for RNA-Seq analysis

DEPENDS+=	fastq-trim>=0:../../wip/fastq-trim
DEPENDS+=	fastqc>=0:../../biology/fastqc
DEPENDS+=	biolibc-tools>=0:../../biology/biolibc-tools
DEPENDS+=	gffread>=0:../../wip/gffread
DEPENDS+=	kallisto>=0:../../biology/kallisto
DEPENDS+=	bwa>=0:../../biology/bwa
DEPENDS+=	bowtie2>=0:../../biology/bowtie2
DEPENDS+=	hisat2>=0:../../biology/hisat2
DEPENDS+=	igv>=0:../../biology/igv
DEPENDS+=	samtools>=0:../../biology/samtools
DEPENDS+=	fasda>=0:../../wip/fasda

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
