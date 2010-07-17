# $NetBSD: Makefile,v 1.2 2010/07/17 07:37:51 obache Exp $
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

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
