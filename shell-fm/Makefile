# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:00 asau Exp $
#

DISTNAME=	shell-fm-0.4
CATEGORIES=	audio net
MASTER_SITES=	http://nex.scrapping.cc/shell-fm/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://nex.scrapping.cc/shell-fm/
COMMENT=	Console based player for Last.FM radio streams


USE_TOOLS+=	autoconf automake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MAKE_DIRS=	${EGDIR}
MESSAGE_SUBST+=	EGDIR=${EGDIR}

pre-configure:
	cd ${WRKSRC} && ./reconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/shell-fm.rc-example ${EGDIR}/shell-fm.rc

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/oss.builtin.mk"
.include "../../mk/bsd.pkg.mk"
