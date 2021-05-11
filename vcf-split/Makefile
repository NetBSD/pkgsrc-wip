# $NetBSD$

DISTNAME=	vcf-split-0.1.1.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	490f0be599fe57e07eb13c1e072a4df998592b7c

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../wip/biolibc/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
