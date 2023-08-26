# $NetBSD$

DISTNAME=	fasda-0.1.4.31
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	4069c6b94a8d65449d943291e56963a1eea93a5a

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
