# $NetBSD: Makefile,v 1.13 2013/01/27 00:01:24 ryo-on Exp $
#

DISTNAME=		libedit-20121213-3.0
PKGNAME=		editline-3.0.20121213
CATEGORIES=		devel
MASTER_SITES=		http://www.thrysoee.dk/editline/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
