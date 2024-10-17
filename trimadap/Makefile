# $NetBSD$

DISTNAME=	trimadap-0.1.4
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
# GITHUB_PROJECT=	trimadap
GITHUB_TAG=	ec5a764e1834363ae0c4b52f52bdb114ff7af265

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/lh3/trimadap
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules
LICENSE=	mit

# WRKSRC=		${WRKDIR}/trimadap-${GITHUB_TAG}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
