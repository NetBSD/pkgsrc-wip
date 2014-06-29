# $NetBSD: Makefile,v 1.7 2014/06/29 17:15:54 cheusov Exp $
#

DISTNAME=	${PKGNAME:S/sjg-mk-files/bmake/}
PKGNAME=	sjg-mk-files-20140620
CATEGORIES=	devel
MASTER_SITES=	http://crufty.net/ftp/pub/sjg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://crufty.net/help/sjg/bmake.html
COMMENT=	Mk-files for bmake from Simon J. Gerraty
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/bmake/mk
USE_LANGUAGES=	# none
NO_BUILD=	yes

MKFILESDIR=		${PREFIX}/share/sjg-mk
INSTALLATION_DIRS=	${MKFILESDIR}

CHECK_INTERPRETER_SKIP+=	share/sjg-mk/meta2deps.py

do-install:
	cd ${WRKSRC} && ${SH} ./install-mk ${DESTDIR}${MKFILESDIR}

.include "../../mk/bsd.pkg.mk"
