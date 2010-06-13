# $NetBSD: Makefile,v 1.11 2010/06/13 22:47:19 thomasklausner Exp $
#

DISTNAME=	swftools-0.9.0
PKGREVISION=	2
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.swftools.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.swftools.org/
COMMENT=	Collection of SWF manipulation and creation utilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake yacc
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

# png2swf already installed as part of ming<=0.4.3. 
CONFIGURE_ENV+=		DISABLEPNG2SWF=true

.include "options.mk"

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}/${PREFIX}/${PKGMANDIR}

BUILDLINK_INCDIRS.fontconfig=	include/fontconfig
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
