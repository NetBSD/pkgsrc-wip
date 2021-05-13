# $NetBSD$

DISTNAME=	vcf-split-0.1.1.6
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	e27d8da4e2e376b79f82ae4ff8d87b322c4dcb40

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../wip/biolibc/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
