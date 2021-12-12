# $NetBSD$

DISTNAME=	ad2vcf-0.1.3.45
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	22296d4e09c5ed1be65b731ccf42ddf19f8b2890

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../wip/libxtend/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
