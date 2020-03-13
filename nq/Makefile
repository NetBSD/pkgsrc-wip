# $NetBSD$

GITHUB_TAG=	b975f8a0571797ee527d534d337b1b1063619d38
DISTNAME=	nq-${GITHUB_TAG}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/leahneukirchen/nq
COMMENT=	Command line queueing utility
LICENSE=	public-domain

EXTRACT_USING=	gtar

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
INSTALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"

