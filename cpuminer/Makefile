# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	cpuminer-2.5.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=pooler/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/pooler/cpuminer/
COMMENT=	CPU miner for Litecoin and Bitcoin
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	cpuminer
GITHUB_TAG=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	minerd

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
