# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 10:52:44 jihbed Exp $
#

DISTNAME=	duplo_0.2.0_src
PKGNAME=	${DISTNAME:S/_0.2.0_src//}-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/duplo/duplo/duplo_0.2.0/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://duplo.giants.ch/
COMMENT=		Duplicated source code blocks C++ language
LICENSE=	    gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

DOCDIR=	${PREFIX}/share/doc/duplo

INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duplo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
