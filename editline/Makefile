# $NetBSD: Makefile,v 1.8 2009/01/11 10:57:19 phonohawk Exp $
#

DISTNAME=		libedit-20080712-2.11
PKGNAME=		editline-2.11
CATEGORIES=		devel
MASTER_SITES=		http://www.thrysoee.dk/editline/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=			automake

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
.include "../../mk/curses.buildlink3.mk"
