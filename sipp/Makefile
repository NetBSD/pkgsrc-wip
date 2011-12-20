# $NetBSD: Makefile,v 1.9 2011/12/20 16:46:02 gschwarz Exp $

DISTNAME=	sipp.svn
PKGNAME=	sipp-3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipp/3.2/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://sipp.sourceforge.net/
COMMENT=	SIPp is a free Open Source SIP test tool/traffic generator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sipp ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.dl}
MAKE_ENV+=	LIBS=${LIBS:Q}
# not automatically added by ../../mk/dlopen.builtin.mk
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
