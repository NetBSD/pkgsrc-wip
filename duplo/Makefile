# $NetBSD: Makefile,v 1.4 2012/11/12 15:59:47 othyro Exp $
#

DISTNAME=	duplo_0.2.0_src
PKGNAME=	${DISTNAME:S/_0.2.0_src//}-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duplo/}

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
