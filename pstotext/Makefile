# $NetBSD: Makefile,v 1.5 2010/04/22 13:03:33 obache Exp $
#

DISTNAME=	pstotext-1.9
CATEGORIES=	print
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/contrib/

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://pages.cs.wisc.edu/~ghost/doc/pstotext.htm
COMMENT=	Postscript to text converter
LICENSE=	pstotext-license
LICENSE_FILE=	pstotext-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_TOOLS+=	gs:run
USE_TOOLS+=	gmake

BUILD_MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pstotext.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../mk/bsd.pkg.mk"
