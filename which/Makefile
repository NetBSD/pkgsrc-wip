# $NetBSD: Makefile,v 1.1.1.1 2004/05/23 04:05:15 jeremy-c-reed Exp $

# this code is from NetBSD's src/usr.bin/whereis/ with slight changes

DISTNAME=	which-1.16  # version from CVS revision
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=
COMMENT=	Locate a command

NO_CHECKSUM=	# defined
PKGMANDIR?=	man  # this will be removed once PKGMANDIR is in real pkgsrc

do-extract:
	${CP} ${FILESDIR}/whereis.c ${WRKDIR}

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o whereis whereis.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/whereis ${PREFIX}/bin/which
	${INSTALL_MAN} ${FILESDIR}/which.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
