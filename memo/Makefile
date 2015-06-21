# $NetBSD: Makefile,v 1.1 2015/06/21 16:53:41 cfkoch Exp $

DISTNAME=	memo-${VERSION}
PKGNAME=	memo-${VERSION}
VERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	-http://www.getmemo.org/memo-${VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.getmemo.org/
COMMENT=	Note-taking software
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}

post-build:
	mkdir -p ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
