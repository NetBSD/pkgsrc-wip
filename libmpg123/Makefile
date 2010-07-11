# $NetBSD: Makefile,v 1.1 2010/07/11 17:40:53 bharder Exp $
#

.include "../../wip/libmpg123/Makefile.common"

PKGNAME=	libmpg123-${LIBMPG123_VERSION}
COMMENT=	MPEG layer 1, 2, and 3 decoder library

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

AUTO_MKDIRS=		yes

BUILD_DIRS=		src/libmpg123
INSTALL_DIRS=		src/libmpg123

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/libmpg123.pc \
		${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "../../devel/libltdl/buildlink3.mk"
.include "mpg123-options.mk"

.include "../../mk/bsd.pkg.mk"
