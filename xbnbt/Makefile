# $NetBSD: Makefile,v 1.1 2007/04/16 19:07:18 loic-hoguin Exp $

DISTNAME=		xbnbt-81b.3.5
CATEGORIES=		net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbnbt/}
EXTRACT_SUFX=	.zip

MAINTAINER=	loic-hoguin@users.sourceforge.net
HOMEPAGE=	http://xbnbt.sourceforge.net/
COMMENT=	Alternative BitTorrent tracker written in C++

WRKSRC=		${WRKDIR}/xbnbt/bnbt/src

USE_LANGUAGES=	c++
USE_TOOLS+=		gmake

MAKE_FILE=		makefile
BUILD_TARGET+=	bnbt

post-extract:
	mv ${WRKDIR:Q}/"copy of xbnbt-81b.3" ${WRKDIR:Q}/xbnbt
	mv ${WRKDIR:Q}/xbnbt/bnbt/examples/"xbnbt ipb2 mod" \
		${WRKDIR:Q}/xbnbt/bnbt/examples/ipb2_mod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnbt ${PREFIX}/sbin

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbnbt
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xbnbt
	${INSTALL_DATA_DIR} ${PREFIX}/share/xbnbt

	cd ${WRKDIR}/xbnbt/bnbt/doc && ${PAX} -rwpam . \
		${PREFIX}/share/doc/xbnbt
	cd ${WRKDIR}/xbnbt/bnbt/examples && ${PAX} -rwpam . \
		${PREFIX}/share/examples/xbnbt
	cd ${WRKDIR}/xbnbt/bnbt/public_http/xbnbt && ${PAX} -rwpam . \
		${PREFIX}/share/xbnbt

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
