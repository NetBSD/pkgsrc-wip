# $NetBSD$

DISTNAME=	fastq-trim-0.1.3.11
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	505ca2678d3a029fed2a44a8b5eabdbc3a7e951b

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

LDFLAGS.SunOS=	-lresolv

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
