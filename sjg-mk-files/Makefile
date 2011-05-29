# $NetBSD: Makefile,v 1.2 2011/05/29 08:17:46 cheusov Exp $
#

DISTNAME=	mk-20110505
PKGNAME=	${DISTNAME:S/mk/sjg-mk-files/}
CATEGORIES=	devel
MASTER_SITES=	http://crufty.net/ftp/pub/sjg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://crufty.net/help/sjg/bmake.html
COMMENT=	mk-files for bmake by Simon J. Gerraty
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mk
USE_LANGUAGES=	# none
NO_BUILD=	yes

MKFILESDIR=		${PREFIX}/share/sjg-mk
INSTALLATION_DIRS=	${MKFILESDIR}

do-install:
	cd ${WRKSRC} && ./install-mk ${DESTDIR}${MKFILESDIR}

.include "../../mk/bsd.pkg.mk"

#MAKE_PROGRAM=	bmake
