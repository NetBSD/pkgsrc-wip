# $NetBSD: Makefile,v 1.1.1.1 2003/12/01 23:44:28 mpasternak Exp $
#

DISTNAME=	pkgconfig-0.15.0
PKGNAME=	mingw-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	System for managing library compile/link flags

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/glib-1.2.8/libtool
NO_MTREE=		yes

# I can't get the settings to work exactly like I want, so:

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./configure --disable-threads --prefix=${CROSSBASE}/${MINGWTARGET} 

post-install:
	${INSTALL_DATA_DIR} ${CROSSBASE}/${MINGWTARGET}/lib/pkgconfig
	${LN} -s ${CROSSBASE}/${MINGWTARGET}/bin/pkg-config ${CROSSBASE}/bin/${MINGWTARGET}-pkg-config

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
