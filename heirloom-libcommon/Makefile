# $NetBSD: Makefile,v 1.1 2007/05/19 13:26:16 cheusov Exp $
.include "../../wip/heirloom-common/Makefile.prog.common"

PKGNAME=	heirloom-libcommon-${HEIRLOOM_VER}
CATEGORIES=	devel

DEPENDS+=	heirloom-doc-${HEIRLOOM_VER}:../../wip/heirloom-doc

MAKE_FLAGS+=	SUBDIRS="libcommon"

INSTALLATION_DIRS+=	include/heirloom

HEADERS_DIR=	${PREFIX}/include/heirloom

HEADERS=	_alloca.h _malloc.h _utmpx.h alloca.h asciitype.h atoll.h \
		blank.h getdir.h iblok.h malloc.h mbtowi.h memalign.h \
		msgselect.h oblok.h pathconf.h pfmt.h regexp.h regexpr.h \
		sfile.h sigset.h utmpx.h

do-install:
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/libcommon/${i} ${HEADERS_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/libcommon/libcommon.a \
		${PREFIX}/lib/libheirloomcommon.a

.include "../../mk/bsd.pkg.mk"
