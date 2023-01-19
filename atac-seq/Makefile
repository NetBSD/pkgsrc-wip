# $NetBSD$
#

DISTNAME=	atac-seq-1.0
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for ATAC-Seq analysis

DEPENDS+=	fastq-trim>=0:../../wip/fastq-trim
DEPENDS+=	fastqc>=0:../../biology/fastqc
DEPENDS+=	biolibc-tools>=0:../../wip/biolibc-tools
DEPENDS+=	gffread>=0:../../biology/gffread
DEPENDS+=	bwa>=0:../../biology/bwa
DEPENDS+=	bowtie2>=0:../../biology/bowtie2
DEPENDS+=	samtools>=0:../../biology/samtools
DEPENDS+=	igv>=0:../../biology/igv
DEPENDS+=	${PYPKGPREFIX}-macs2>=0:../../wip/py-macs2
DEPENDS+=	fasda>=0:../../wip/fasda
DEPENDS+=	peak-classifier>=0:../../wip/peak-classifier
DEPENDS+=	webbrowser>=0:../../wip/webbrowser

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
