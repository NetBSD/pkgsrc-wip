# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:39 asau Exp $
#

.include "../../wip/libmpg123/Makefile.common"

PKGNAME=	libmpg123-${LIBMPG123_VERSION}
COMMENT=	MPEG layer 1, 2, and 3 decoder library

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

AUTO_MKDIRS=		yes

BUILD_DIRS=		src/libmpg123
INSTALL_DIRS=		src/libmpg123

post-install:
	${INSTALL_DATA} ${WRKSRC}/libmpg123.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/libltdl/buildlink3.mk"
.include "mpg123-options.mk"

.include "../../mk/bsd.pkg.mk"
