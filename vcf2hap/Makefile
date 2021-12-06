# $NetBSD$

DISTNAME=	vcf2hap-0.1.3.16
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	dfaef553fc9dbf3f0d6a9c62e91b2a01a062f6fe

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf2hap
COMMENT=	Generate .hap file from VCF for haplohseq
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../wip/libxtend/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
