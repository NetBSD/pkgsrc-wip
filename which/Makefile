# $NetBSD: Makefile,v 1.5 2008/11/06 21:17:51 cheusov Exp $

# this code is from NetBSD's src/usr.bin/whereis/ with slight changes

DISTNAME=	which-1.16  # version from CVS revision
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=
COMMENT=		Locate a command

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}

NO_CONFIGURE=		yes
NO_CHECKSUM=		yes

AUTO_MKDIRS=		yes

do-extract:
	${MKDIR} ${WRKSRC} && \
	${CP} ${FILESDIR}/whereis.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o whereis whereis.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whereis ${DESTDIR}${PREFIX}/bin/which
	${INSTALL_MAN} ${FILESDIR}/which.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
