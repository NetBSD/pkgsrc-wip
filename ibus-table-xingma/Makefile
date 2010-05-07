# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 11:37:32 obache Exp $
#

DISTNAME=	ibus-table-xingma-1.2.0.20100305
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The struct tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-extra-phrases

.include "../../wip/ibus-table-extraphrase/buildlink3.mk"
.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
