# $NetBSD: Makefile,v 1.1.1.1 2010/01/15 11:29:21 obache Exp $
#

DISTNAME=	ibus-table-erbi-1.2.0.20090901
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Erbi and Erbi (Qin Sung) input method on IBus Table
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

#XXX: should be optionify?
#CONFIGURE_ARGS+=	--enable-extra-phrases

#.include "../../wip/ibus-table-extraphrase/buildlink3.mk"
.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
