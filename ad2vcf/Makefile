# $NetBSD$

DISTNAME=	ad2vcf-0.1.5.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	16ae5d5c92d9f7a9e6342a48998b30ba222c784f

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
