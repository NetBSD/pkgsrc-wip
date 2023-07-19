# $NetBSD$

DISTNAME=	fasda-0.1.3.20
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	2aa3d73ae4728a0e78c18c115b185de9958d0992

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

DEPENDS=	stringtie>0:../../wip/stringtie

LDFLAGS.SunOS+=	-lresolv

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
