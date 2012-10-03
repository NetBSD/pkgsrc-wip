# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:55 asau Exp $
#

DISTNAME=		mksend-0.5.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.nopcode.org/prj/mksend/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mksend
COMMENT=		Network testing tool for capture and generate packets

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

.include "../../wip/libparsifal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
