# $NetBSD$
#

DISTNAME=	rna-seq-1.1
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for RNA-Seq analysis

DEPENDS+=	fastq-trim>=0:../../wip/fastq-trim
DEPENDS+=	fastqc>=0:../../biology/fastqc
DEPENDS+=	biolibc-tools>=0:../../wip/biolibc-tools
DEPENDS+=	gffread>=0:../../biology/gffread
DEPENDS+=	kallisto>=0:../../biology/kallisto
DEPENDS+=	hisat2>=0:../../biology/hisat2
DEPENDS+=	samtools>=0:../../biology/samtools
DEPENDS+=	igv>=0:../../biology/igv
DEPENDS+=	fasda>=0:../../wip/fasda
DEPENDS+=	webbrowser>=0:../../wip/webbrowser
DEPENDS+=	${PYPKGPREFIX}-multiqc-[0-9]*:../../wip/py-multiqc

META_PACKAGE=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
