# $NetBSD$

DISTNAME=	ad2vcf-0.1.3.26
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	67ef5b6cb2e293b989da8f84275a82c88e528b57

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../wip/libxtend/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
