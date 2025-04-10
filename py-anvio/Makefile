# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Mon Nov  5 13:17:05 CST 2018               #
###########################################################

###########################################################
# Unconverted and partially converted FreeBSD port syntax:

# 3rd-party: http://merenlab.org/2016/06/18/installing-third-party-software/
# Need: modeller

DISTNAME=	anvio-${PV}
PKGNAME=	${PYPKGPREFIX}-anvio-${PV}
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_GITHUB:=merenlab/}
GITHUB_PROJECT=	anvio
GITHUB_TAG=	v${PV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://merenlab.org/software/anvio/
COMMENT=	Analysis and visualization platform for 'omics data
LICENSE=	gnu-gpl-v3

DEPENDS=	samtools>0:../../wip/samtools \
		hmmer>0:../../wip/hmmer \
		FastTree>0:../../wip/fasttree \
		muscle>0:../../wip/muscle \
		R>0:../../math/R \
		R-gridExtra>0:../../graphics/R-gridExtra \
		R-ggplot2>0:../../graphics/R-ggplot2 \
		R-gtools>0:../../math/R-gtools \
		${PYPKGPREFIX}-mistune>0:../../textproc/py-mistune \
		${PYPKGPREFIX}-pandas>0:../../math/py-pandas \
		${PYPKGPREFIX}-django>0:../../www/py-django \
		${PYPKGPREFIX}-requests>0:../../devel/py-requests \
		${PYPKGPREFIX}-bottle>0:../../www/py-bottle \
		${PYPKGPREFIX}-psutil>0:../../sysutils/py-psutil \
		${PYPKGPREFIX}-scikit-learn>0:../../math/py-scikit-learn \
		${PYPKGPREFIX}-h5py>0:../../devel/py-h5py \
		${PYPKGPREFIX}-biopython>0:../../biology/py-biopython \
		Prodigal>0:../../wip/prodigal \
		centrifuge>0:../../wip/centrifuge \
		mcl>0:../../wip/mcl \
		xssp>0:../../wip/xssp \
		FAMSA>0:../../wip/famsa \
		R-optparse>0:../../wip/R-optparse \
		${PYPKGPREFIX}-pysam>0:../../wip/py-pysam \
		${PYPKGPREFIX}-ete3>0:../../wip/py-ete3 \
		${PYPKGPREFIX}-eggnog-mapper>0:../../wip/py-eggnog-mapper \
		${PYPKGPREFIX}-snakemake>0:../../wip/py-snakemake

USE_TOOLS=	bash
REPLACE_BASH=	anvio/workflows/metagenomics/test/*.sh tests/*.sh tests/*/*.sh
REPLACE_BASH+=	sandbox/anvi-script-FASTA-to-contigs-db sandbox/*.sh
REPLACE_PYTHON=	tests/server/run_server_tests.py

REPLACE_R=	sandbox/anvi-script-gen_stats_for_single_copy_genes.R

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env Rscript
REPLACE.R.new=		${PREFIX}/bin/R
REPLACE_FILES.R=	${REPLACE_R}

PYTHON_VERSIONS_INCOMPATIBLE=	27

PV=		5.2

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
