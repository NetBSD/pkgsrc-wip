# $NetBSD: Makefile,v 1.7 2008/07/12 15:08:48 gschwarz Exp $

DISTNAME=	sipp.3.1.src
PKGNAME=	sipp-3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipp/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://sipp.sourceforge.net/
COMMENT=	SIPp is a free Open Source SIP test tool/traffic generator

WRKSRC=		${WRKDIR}/sipp.svn
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
