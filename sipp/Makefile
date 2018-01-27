# $NetBSD: Makefile,v 1.11 2014/12/30 16:37:05 gschwarz Exp $

DISTNAME=	v3.5.1
PKGNAME=	${DISTNAME:S/v/sipp-/}
CATEGORIES=	net
MASTER_SITES=	https://github.com/SIPp/sipp/archive/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://sipp.sourceforge.net/
COMMENT=	SIPp is a free Open Source SIP test tool/traffic generator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake autoconf automake autoreconf
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
INSTALL_TARGET=		install install-man1
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC} && autoreconf -vifs

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
