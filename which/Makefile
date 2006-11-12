# $NetBSD: Makefile,v 1.4 2006/11/12 17:45:39 cheusov Exp $

# this code is from NetBSD's src/usr.bin/whereis/ with slight changes

DISTNAME=	which-1.16  # version from CVS revision
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=
COMMENT=	Locate a command

WRKSRC=		${WRKDIR}/${DISTNAME}

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
PKGMANDIR?=	man  # this will be removed once PKGMANDIR is in real pkgsrc

do-extract:
	${MKDIR} ${WRKSRC} && \
	${CP} ${FILESDIR}/whereis.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o whereis whereis.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whereis ${PREFIX}/bin/which
	${INSTALL_MAN} ${FILESDIR}/which.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
