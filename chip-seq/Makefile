# $NetBSD: Makefile,v 1.5 2023/11/05 23:48:31 wiz Exp $

# Update minor version when adding or removing dependencies
# Update revision for all other changes
DISTNAME=	chip-seq-1.2
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for ChIP-Seq analysis

DEPENDS+=	sra-tools>0:../../wip/sra-tools
DEPENDS+=	fastq-trim>0:../../wip/fastq-trim
DEPENDS+=	fastqc>0:../../biology/fastqc
DEPENDS+=	biolibc-tools>0:../../wip/biolibc-tools
DEPENDS+=	gffread>0:../../biology/gffread
DEPENDS+=	bwa>0:../../biology/bwa
DEPENDS+=	bowtie2>0:../../biology/bowtie2
DEPENDS+=	samtools>0:../../biology/samtools
DEPENDS+=	igv>0:../../biology/igv
DEPENDS+=	${PYPKGPREFIX}-macs2>0:../../wip/py-macs2
DEPENDS+=	fasda>0:../../wip/fasda
DEPENDS+=	peak-classifier>0:../../wip/peak-classifier
DEPENDS+=	${PYPKGPREFIX}-multiqc-[0-9]*:../../wip/py-multiqc
DEPENDS+=	webbrowser>0:../../wip/webbrowser
DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	lz4>0:../../archivers/lz4
DEPENDS+=	xz>0:../../archivers/xz
DEPENDS+=	zstd>0:../../archivers/zstd

META_PACKAGE=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
