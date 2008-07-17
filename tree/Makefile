# $NetBSD: Makefile,v 1.1.1.1 2008/07/17 16:32:20 phonohawk Exp $
#

DISTNAME=	tree-1.5.1.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cjs@NetBSD.org
HOMEPAGE=	http://mama.indstate.edu/users/ice/tree/
COMMENT=	Print a text or HTML tree diagram of a directory structure

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		MANSUBDIR=${PKGMANDIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

.include "../../mk/bsd.pkg.mk"
