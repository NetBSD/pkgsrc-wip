# $NetBSD$

DISTNAME=	fasda-0.1.3.27
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	7d2e51b6e23607278609df3ef3e4139e9f0b4119

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
