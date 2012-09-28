# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:39 asau Exp $
#

DISTNAME=	duplo_0.2.0_src
PKGNAME=	${DISTNAME:S/_0.2.0_src//}-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/duplo/duplo/duplo_0.2.0/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://duplo.giants.ch/
COMMENT=	Find duplicated code blocks in large C/C++/Java/C
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

DOCDIR=	${PREFIX}/share/doc/duplo

INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duplo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
