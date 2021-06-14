# $NetBSD$

DISTNAME=	peak-classifier-0.1.0.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	69e702c224e71a3016b40bc67d742a32f990e67b

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/peak-classifier
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF
LICENSE=	2-clause-bsd

DEPENDS+=	bedtools>=0:../../biology/bedtools

REPLACE_PYTHON=	feature-view.py

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
