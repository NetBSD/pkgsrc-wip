# $NetBSD$

DISTNAME=	fastq-trim-0.1.2.10
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	665c81d434579a370aa6828c1765a959a80b9290

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_ENV=	VERSION=${PKGVERSION}

LDFLAGS.SunOS=	-lresolv

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
