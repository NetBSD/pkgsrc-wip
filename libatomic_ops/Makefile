# $NetBSD: Makefile,v 1.1 2007/06/23 08:48:13 bsadewitz Exp $
#

DISTNAME=	libatomic_ops-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/research/linux/atomic_ops/download/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.hpl.hp.com/research/linux/atomic_ops/
COMMENT=	Atomic operations library from HP

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes	# XXX GNU configure doesn't work right yet.  Help! ;)
USE_TOOLS+=	gmake

INSTALLATION_DIRS_FROM_PLIST=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
