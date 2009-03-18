# $NetBSD: Makefile,v 1.10 2009/03/18 12:34:24 cheusov Exp $
#

DISTNAME=		libedit-20080712-2.11
PKGNAME=		editline-2.11
CATEGORIES=		devel
MASTER_SITES=		http://www.thrysoee.dk/editline/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=			automake

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
