# $NetBSD$

DISTNAME=	ad2vcf-0.1.1.65
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_PROJECT=	ad2vcf
GITHUB_TAG=	a23ca09f1c990b27bd2dbd7d292c2cd9fb02d7f1

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
