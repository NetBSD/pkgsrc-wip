# $NetBSD: Makefile,v 1.5 2014/02/10 21:08:18 jihbed Exp $
#

DISTNAME=	duplo_0.2.0_src
PKGNAME=	${DISTNAME:S/_0.2.0_src//}-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duplo/}

MAINTAINER=	kamelderouiche@yahoo.com
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
