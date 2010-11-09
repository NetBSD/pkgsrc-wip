# $NetBSD: Makefile,v 1.14 2010/11/09 21:09:19 mjoellnir Exp $
#

DISTNAME=		nzbget-0.7.0-testing
PKGNAME=		${DISTNAME:S/-testing//}
PKGREVISION=		1
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nzbget/}
EXTRACT_SUFX=		-r380.tar.gz

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://sourceforge.net/projects/nzbget/
COMMENT=		Binary newsreader with NZB support

USE_TOOLS+=		gmake
USE_TOOLS+=		autoconf
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/nzbget
MESSAGE_SUBST+=		EGDIR=${EGDIR}

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf.example \
		${EGDIR}/nzbget.conf.example

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libpar2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
