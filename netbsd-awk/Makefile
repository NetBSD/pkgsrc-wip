# $NetBSD: Makefile,v 1.2 2007/01/09 08:39:45 cheusov Exp $
#

DISTNAME=	netbsd-awk-20070105
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of AWK

USE_TOOLS+=	bison lex
MAKE_FILE=	makefile
BUILD_TARGET=	a.out

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-I.
LDFLAGS+=	-lm
MAKE_FLAGS+=	YHEADER=yes

post-patch:
	sed -e 's|awk|nbawk|g' ${WRKSRC}/awk.1 > ${WRKSRC}/nbawk.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbawk.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nbawk

.if ${OPSYS} == "Linux"
# Linux has no strlcat function
.include "../../pkgtools/libnbcompat/buildlink3.mk"
CPPFLAGS+=	-I${LOCALBASE}/include/libnbcompat
LDFLAGS+=	-lnbcompat
.endif

.include "../../mk/bsd.pkg.mk"
