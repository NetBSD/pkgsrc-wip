# $NetBSD: Makefile,v 1.13 2011/05/13 07:36:24 ryo-on Exp $
#

DISTNAME=		cclive-0.7.3.1
CATEGORIES=		net multimedia www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cclive/}

MAINTAINER= 		zecrazytux@zecrazytux.net
HOMEPAGE=		http://code.google.com/p/cclive/
COMMENT=		Command line video extraction tool for user-uploaded video hosts
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++ c
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes

SUBST_CLASSES+=		man-path
SUBST_STAGE.man-path+=	pre-configure
SUBST_FILES.man-path+=	man1/CMakeLists.txt
SUBST_SED.man-path=	-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../net/quvi/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
