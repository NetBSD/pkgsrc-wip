# $NetBSD$
#
# Update minor version when adding/removing dependencies
# Update revision for lesser changes

DISTNAME=	rna-seq-1.3.0
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for RNA-Seq analysis

DEPENDS+=	sra-tools>0:../../wip/sra-tools
DEPENDS+=	fastq-trim>0:../../wip/fastq-trim
DEPENDS+=	fastqc>0:../../biology/fastqc
DEPENDS+=	biolibc-tools>0:../../wip/biolibc-tools
DEPENDS+=	gffread>0:../../biology/gffread
DEPENDS+=	kallisto>0:../../biology/kallisto
DEPENDS+=	hisat2>0:../../biology/hisat2
DEPENDS+=	rna-star>0:../../wip/rna-star
DEPENDS+=	samtools>0:../../biology/samtools
DEPENDS+=	igv>0:../../biology/igv
DEPENDS+=	fasda>0:../../wip/fasda
DEPENDS+=	webbrowser>0:../../wip/webbrowser
DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	lz4>0:../../archivers/lz4
DEPENDS+=	xz>0:../../archivers/xz
DEPENDS+=	zstd>0:../../archivers/zstd

META_PACKAGE=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
