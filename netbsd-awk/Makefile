# $NetBSD: Makefile,v 1.6 2007/10/25 09:20:49 cheusov Exp $
#

DISTNAME=	netbsd-awk-20070105
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of AWK

USE_FEATURES=	nbcompat
USE_TOOLS+=	bison lex
MAKE_FILE=	makefile
BUILD_TARGET=	a.out

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	LIBS="${LIBS}"

CFLAGS+=	-I.
CFLAGS+=	-DAWK_FOPEN_MAX=3072
LDFLAGS+=	-lm

MAKE_FLAGS+=	YHEADER=yes

post-patch:
	sed -e 's|awk|nbawk|g' ${WRKSRC}/awk.1 > ${WRKSRC}/nbawk.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbawk.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nbawk

.include "../../mk/bsd.pkg.mk"
