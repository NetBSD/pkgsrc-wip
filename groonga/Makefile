# $NetBSD: Makefile,v 1.2 2010/08/08 12:54:17 obache Exp $
#

DISTNAME=	groonga-0.7.4
CATEGORIES=	textproc
MASTER_SITES=	http://groonga.org/files/groonga/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://groonga.org/
COMMENT=	Fulltext search engine and column store
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

PKGCONFIG_OVERRIDE+=	groonga.pc.in

CHECK_WRKREF_SKIP+=	bin/groonga

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
