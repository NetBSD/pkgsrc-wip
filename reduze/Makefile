# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 10:48:08 jihbed Exp $
#

DISTNAME=	reduze-1.2
CATEGORIES=	physics
MASTER_SITES=	http://www.qgd.unizh.ch/~cedric/reduze/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.qgd.unizh.ch/~cedric/reduze/download/
COMMENT=	Program for reducing Feynman Integrals
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+= pkg-config
USE_LANGUAGES=	c c++

EDGDIR=	${PREFIX}/examples/reduze

INSTALLATION_DIRS=	${EDGDIR}

post-install:
	#${INSTALL_DATA} ${WRKSRC}/doc/tutorial/reduze.pdf ${DESTDIR}${PREFIX}/doc/reduze
	${INSTALL_DATA} ${WRKSRC}/example/*.in  ${DESTDIR}${EDGDIR}

.include "../../wip/libginac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
