# $NetBSD$

GITHUB_TAG=	b975f8a0571797ee527d534d337b1b1063619d38
DISTNAME=	nq-${GITHUB_TAG}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=christiank/}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Command line queueing utility
HOMEPAGE=	https://github.com/chneukirchen/nq/
LICENSE=	public-domain

EXTRACT_USING=	gtar

WRKSRC=		${WRKDIR}/${PKGNAME}
INSTALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"

