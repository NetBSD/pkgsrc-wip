# $NetBSD$

DISTNAME=	fasda-0.1.3.7
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	7fe80cf3f52ad0e5c782922d3d60c6a546c2199f

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

LDFLAGS.SunOS+=	-lresolv

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
