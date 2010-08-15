# $NetBSD: Makefile,v 1.12 2010/08/15 01:04:52 obache Exp $
#

DISTNAME=	swftools-0.9.1
CATEGORIES=	graphics multimedia converters
MASTER_SITES=	http://www.swftools.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.swftools.org/
COMMENT=	Collection of SWF manipulation and creation utilities
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake yacc
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

# png2swf already installed as part of ming>=0.4.3. 
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
