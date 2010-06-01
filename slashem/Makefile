# $NetBSD: Makefile,v 1.1.1.1 2010/06/01 06:05:45 obache Exp $
#

PKGNAME=	slashem-0.0.7E7F3nb1
DISTNAME=	se007e7f3
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/slashem/slashem-source/0.0.7E7F3/

MAINTAINER=	lifanov@mail.lifanov.com
HOMEPAGE=	http://slashem.sourceforge.net/
COMMENT=	Slash'EM is a Nethack variant with more stuff
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/slashem-0.0.7E7F3
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC}/sys/unix && chmod +x setup.sh
	cd ${WRKSRC}/sys/unix && ./setup.sh
	cd ${WRKSRC} && sed -e "s/\/usr/\/usr\/pkg/" -I "" Makefile
	cd ${WRKSRC} && sed -e "s/\/local//" -I "" Makefile

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

.include "../../mk/bsd.pkg.mk"
