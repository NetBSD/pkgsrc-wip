# $NetBSD: Makefile,v 1.2 2011/06/16 03:08:55 makoto Exp $

PKGNAME=	ja-freewnn-server-1.11alpha22
CONFIGURE_ARGS+=	--disable-libraries
# Following two lines gives equivalent to previous 1.10 version
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

CONFIGURE_ARGS+=	--with-wnn-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-libwnn=yes
CONFIGURE_ARGS+=	--disable-sub-bindir
# use sbin/ instead of bin/
CONFIGURE_ARGS+=	--disable-traditional-layout

RCD_SCRIPTS=    ja_freewnn

DEPENDS+=	ja-freewnn-lib>=1.11alpha22:../../wip/ja-freewnn-lib

FILESDIR=       ${.CURDIR}/../ja-freewnn-lib/files
DISTINFO_FILE=  ${.CURDIR}/../ja-freewnn-lib/distinfo
PATCHDIR=       ${.CURDIR}/../ja-freewnn-lib/patches

post-install:
		(cd ${WRKSRC};  \
		env DESTDIR=${DESTDIR} ${MAKE} install.man )

.include "../../wip/ja-freewnn-lib/Makefile.common"
.include "../../wip/ja-freewnn-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
