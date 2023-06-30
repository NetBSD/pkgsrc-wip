# $NetBSD$

DISTNAME=	fasda-0.1.3.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f73ba816467c0389f84d990015eabb2eee393b98

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

LDFLAGS.SunOS+=	-lresolv

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
