# $NetBSD: Makefile,v 1.10 2008/07/22 17:04:03 cheusov Exp $
#

DISTNAME=	netbsd-awk-20080721
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		# none
COMMENT=		NetBSD version of AWK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		nbcompat
USE_TOOLS+=		bison lex
MAKE_FILE=		makefile
BUILD_TARGET=		a.out

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-I.

MAKE_FLAGS+=	LIBS=${LIBS:Q}
MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS}
MAKE_FLAGS+=	YHEADER=yes

post-patch:
	sed -e 's|awk|nbawk|g' ${WRKSRC}/awk.1 > ${WRKSRC}/nbawk.1
	ln -s ${WRKSRC}/ytab.h ${WRKSRC}/awkgram.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbawk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${DESTDIR}${PREFIX}/bin/nbawk

.include "../../mk/bsd.pkg.mk"
