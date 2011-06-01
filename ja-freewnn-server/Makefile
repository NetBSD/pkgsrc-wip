# $NetBSD: Makefile,v 1.1.1.1 2011/06/01 14:41:31 makoto Exp $

PKGNAME=	ja-freewnn-server-1.1.1_pl22
CONFIGURE_ARGS+=	--disable-libraries
# Following two lines gives equivalent to previous version
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

CONFIGURE_ARGS+=	--with-wnn-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-libwnn=yes
CONFIGURE_ARGS+=	--disable-sub-bindir
# use sbin/ instead of bin/
CONFIGURE_ARGS+=	--disable-traditional-layout

#INSTALL_TARGET=		install install.man
# install.man
#MAKE_ENV+=             "DESTDIR=${DESTDIR}"

RCD_SCRIPTS=    ja_freewnn

DEPENDS+=	ja-freewnn-lib>=1.1.1:../../wip/ja-freewnn-lib

FILESDIR=       ${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=  ${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=       ${.CURDIR}/../ja-freewnn-lib/patches

post-install:
		(cd ${WRKSRC};  \
		env DESTDIR=${DESTDIR} ${MAKE} install.man )

.include "../../wip/ja-freewnn-lib/Makefile.common"
.include "../../wip/ja-freewnn-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
