# $NetBSD: Makefile,v 1.1.1.1 2003/06/03 16:17:32 xtraeme Exp $
#

DISTNAME=	weewm-0.01
WRKSRC=         ${WRKDIR}/weewm
CATEGORIES=	wm
MASTER_SITES=	http://www.weewm.org/download/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.weewm.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control

USE_BUILDLINK2=		yes
USE_X11=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/weewm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
