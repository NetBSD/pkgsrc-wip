# $NetBSD$

DISTNAME=	trimadap-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
GITHUB_PROJECT=	trimadap
GITHUB_TAG=	ddfef210563830d9193b40949da3523b6fb93003

MAINTAINER=	dsiercks@uwm.edu
HOMEPAGE=	https://github.com/lh3/seqtk
COMMENT=	Tool for processing sequences in FASTA/FASTQ format
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/trimadap-${GITHUB_TAG}

PORTVERSION=	0.2.20170211

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
