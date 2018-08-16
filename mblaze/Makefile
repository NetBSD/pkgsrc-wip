# $NetBSD$

DISTNAME=	mblaze-0.3.2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=chneukirchen/}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/chneukirchen/mblaze/
COMMENT=	Set of Maildir utilities
LICENSE=	public-domain

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q} BINDIR=${PREFIX:Q}/bin MANDIR=${PREFIX:Q}/${PKGMANDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
