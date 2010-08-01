# $NetBSD: Makefile,v 1.5 2010/08/01 14:57:10 asau Exp $
#

DISTNAME=	ski-1.3.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ski/}

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	http://ski.sourceforge.net/
COMMENT=	The ia64 instruction set simulator

PKG_DESTDIR_SUPPORT=        user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES+= c fortran77 c++
CONFIGURE_ARGS+= --prefix=/usr/pkg

USE_TOOLS+=	aclocal autoconf automake
USE_LIBTOOL=	yes
USE_NCURSES=	yes

pre-configure:
#	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh ${CONFIGURE_ARGS}
	cd ${WRKSRC} && ${SH} ./autogen.sh ${CONFIGURE_ARGS}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/src/XSki \
			${DESTDIR}${PREFIX}/lib/X11/app-defaults/XSki

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
