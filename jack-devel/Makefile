# $NetBSD: Makefile,v 1.1 2007/02/09 12:16:42 bsadewitz Exp $
#

DISTNAME=	jack-0.102.28.svn20061216
PKGNAME=		jack-0.102.28
CATEGORIES=	audio
MASTER_SITES=	http://www.rncbc.org/jack/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.jackaudio.org/
COMMENT=	Development version of the Jack Audio Connection Kit

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	jack.pc.in

CONFIGURE_ENV+=	ac_cv_header_readline_chardefs_h=yes

LIBS+=		${LIBOSSAUDIO}

.include "options.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
