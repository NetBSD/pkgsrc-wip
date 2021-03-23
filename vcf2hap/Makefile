# $NetBSD$

DISTNAME=	vcf2hap-0.1.1.21
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	b15aa140cb4d295d0a97787cecca8bbe314bbe92

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf2hap
COMMENT=	Generate .hap file from VCF for haplohseq
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
