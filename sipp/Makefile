# $NetBSD: Makefile,v 1.6 2006/11/11 11:31:06 shattered Exp $

DISTNAME=	sipp.1.0
PKGNAME=	sipp-1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipp/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://sipp.sourceforge.net/
COMMENT=	SIPp is a free Open Source SIP test tool/traffic generator

WRKSRC=		${WRKDIR}/sipp
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sipp ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.dl}
MAKE_ENV+=	LIBS=${LIBS:Q}
# not automatically added by ../../mk/dlopen.builtin.mk
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
