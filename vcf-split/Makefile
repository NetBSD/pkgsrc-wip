# $NetBSD$

DISTNAME=	vcf-split-0.1.2.13
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f4215f5486fe33b6659fb46162948d58cd823f13

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/biolibc/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
