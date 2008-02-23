# $NetBSD: Makefile,v 1.2 2008/02/23 17:41:34 leot1990 Exp $
#

DISTNAME=	dvtm-0.4
CATEGORIES=	misc
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.brain-dump.org/projects/dvtm/
COMMENT=	Dynamic virtual terminal manager

USE_LANGUAGES=	c99

NO_CONFIGURE=   yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvtm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvtm.1 ${PREFIX}/${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
