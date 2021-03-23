# $NetBSD$

DISTNAME=	ad2vcf-0.1.1.64
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_PROJECT=	ad2vcf
GITHUB_TAG=	69d7feaba0776861df87e50361f837034616454b

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../biology/htslib/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
