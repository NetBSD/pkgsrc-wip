# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:08 asau Exp $
#

DISTNAME=		wsmake-0.6.4
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wsmake/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/wsmake/
COMMENT=		Software for production and maintenance of web sites

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
#USE_BZIP2=		yes
TEST_TARGET=		check

# SUBST_CLASSES+=		voidptr
# SUBST_STAGE.voidptr=	post-patch
# SUBST_MESSAGE.voidptr=	Replacing void * with char *
# SUBST_FILES.voidptr=	libwsmake/wsUtil.cpp
# SUBST_SED.voidptr=	s/void\*/char\*/

.include "../../mk/bsd.pkg.mk"
