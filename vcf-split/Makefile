# $NetBSD$

DISTNAME=	vcf-split-0.1.3.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	ff5f4dee175dd99c0977f0dc5a0878ad28a8502e

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	PKGVERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/biolibc/buildlink3.mk"
.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
