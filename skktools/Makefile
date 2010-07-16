# $NetBSD: Makefile,v 1.1.1.1 2010/07/16 10:49:58 ryo-on Exp $
#
# Imported from uebayasi@NetBSD.org's wip-jp/skktools, and modified.
#

DISTNAME=	skktools-1.3.1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://openlab.ring.gr.jp/skk/
COMMENT=	SKK dictionary manipulation tools

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	skkserv-3.9.4nb[1-6]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-gdbm
#CONFIGURE_ARGS+=--without-skkdic-expr2

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
