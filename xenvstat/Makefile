# $NetBSD: Makefile,v 1.1.1.1 2004/11/27 13:55:36 rxg Exp $

DISTNAME=	xenvstat-20041127
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
COMMENT=	X11-based display environmental sensor readings

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

USE_X11=	yes
USE_BUILDLINK3=	yes

LIBS=		-lXmu -lXext -lXt -lX11 -lm

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/xenvstat ${WRKSRC}/xenvstat.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgclean ${PREFIX}/bin/pkgclean
	${INSTALL_DATA} ${WRKSRC}/Xenvstat ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
