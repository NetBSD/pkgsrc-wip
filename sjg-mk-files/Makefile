# $NetBSD: Makefile,v 1.6 2012/11/13 22:25:50 othyro Exp $
#

DISTNAME=	mk-20111010
PKGNAME=	${DISTNAME:S/mk/sjg-mk-files/}
CATEGORIES=	devel
MASTER_SITES=	http://crufty.net/ftp/pub/sjg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://crufty.net/help/sjg/bmake.html
COMMENT=	Simon J. Gerraty's mk-files for bmake
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/mk
USE_LANGUAGES=	# none
NO_BUILD=	yes

MKFILESDIR=		${PREFIX}/share/sjg-mk
INSTALLATION_DIRS=	${MKFILESDIR}

CHECK_INTERPRETER_SKIP+=	share/sjg-mk/meta2deps.py

do-install:
	cd ${WRKSRC} && ./install-mk ${DESTDIR}${MKFILESDIR}

.include "../../mk/bsd.pkg.mk"
