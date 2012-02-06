# $NetBSD: Makefile,v 1.4 2012/02/06 23:14:26 cheusov Exp $
#

DISTNAME=	mk-20111010
PKGNAME=	${DISTNAME:S/mk/sjg-mk-files/}
CATEGORIES=	devel
MASTER_SITES=	http://crufty.net/ftp/pub/sjg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://crufty.net/help/sjg/bmake.html
COMMENT=	mk-files for bmake by Simon J. Gerraty
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mk
USE_LANGUAGES=	# none
NO_BUILD=	yes

MKFILESDIR=		${PREFIX}/share/sjg-mk
INSTALLATION_DIRS=	${MKFILESDIR}

CHECK_INTERPRETER_SKIP+=	share/sjg-mk/meta2deps.py

do-install:
	cd ${WRKSRC} && ./install-mk ${DESTDIR}${MKFILESDIR}

.include "../../mk/bsd.pkg.mk"
