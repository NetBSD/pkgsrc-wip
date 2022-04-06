# $NetBSD$

DISTNAME=	vcf-split-0.1.4.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	82657a5759e6857850e55e03e3df5e63e2c6ba90

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
