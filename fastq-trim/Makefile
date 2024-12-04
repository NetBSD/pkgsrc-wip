# $NetBSD$

DISTNAME=	fastq-trim-0.1.3.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	56750198255ba409801574f67b168258651efadc

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

LDFLAGS.SunOS=	-lresolv

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
