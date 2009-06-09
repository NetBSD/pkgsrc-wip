# $NetBSD: Makefile,v 1.1 2009/06/09 17:19:16 marko_schuetz Exp $
#

DISTNAME=		tardy-1.17
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tardy/}

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://tardy.sourceforge.net/
COMMENT=		Manipulate attributes of files within tar archives

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++ c

.include "options.mk"

TEST_TARGET=		sure

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
