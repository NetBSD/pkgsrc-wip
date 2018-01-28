# $NetBSD: Makefile,v 1.6 2012/10/07 19:11:30 asau Exp $

DISTNAME=	xbnbt-81b.3.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbnbt/}
EXTRACT_SUFX=	.zip

MAINTAINER=	loic-hoguin@users.sourceforge.net
HOMEPAGE=	http://xbnbt.sourceforge.net/
COMMENT=	Alternative BitTorrent tracker written in C++

WRKSRC=		${WRKDIR}/xbnbt/bnbt/src

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pax

BUILD_TARGET+=	bnbt

INSTALLATION_DIRS+=	sbin share/doc/xbnbt share/examples/xbnbt share/xbnbt

post-extract:
	mv ${WRKDIR}/"Copy of xbnbt-81b.3" ${WRKDIR}/xbnbt
	mv ${WRKDIR}/xbnbt/bnbt/examples/"XBNBT IPB2 Mod" \
		${WRKDIR}/xbnbt/bnbt/examples/ipb2_mod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnbt ${DESTDIR}${PREFIX}/sbin
	cd ${WRKDIR}/xbnbt/bnbt/doc && pax -rwpam . \
		${DESTDIR}${PREFIX}/share/doc/xbnbt
	cd ${WRKDIR}/xbnbt/bnbt/examples && pax -rwpam . \
		${DESTDIR}${PREFIX}/share/examples/xbnbt
	cd ${WRKDIR}/xbnbt/bnbt/public_http/xbnbt && pax -rwpam . \
		${DESTDIR}${PREFIX}/share/xbnbt

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
