# $NetBSD$

DISTNAME=	peak-classifier-0.1.0.14
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	49fc7e0a57c2253d6a74bc06f3f9d7f4d4259948

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
