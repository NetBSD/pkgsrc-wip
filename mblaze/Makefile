# $NetBSD$

GITHUB_PROJECT=	mblaze
DISTNAME=	v0.3.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=chneukirchen/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/chneukirchen/mblaze/
COMMENT=	Set of Maildir utilities
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/mblaze-0.3.2

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q} BINDIR=${PREFIX:Q}/bin MANDIR=${PREFIX:Q}/man

.include "../../mk/bsd.pkg.mk"
