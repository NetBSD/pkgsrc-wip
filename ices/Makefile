# $NetBSD: Makefile,v 1.12 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=	ices-0.2.3
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	MP3/Vorbis encoder for icecast servers


GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lame=${BUILDLINK_PREFIX.lame} \
			--with-perl=${BUILDLINK_PREFIX.perl} \
			--with-xml=${BUILDLINK_PREFIX.libxml2}/bin \
			--with-docdir=${LOCALBASE}/share/doc/ices \
			--with-libshout=${BUILDLINK_PREFIX.libshout}

.include "../../audio/libshout/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"

# Set USE_VORBIS to optionally include these in ices
#

# For Python support, we need a shared library..
#.if defined(USE_PYTHON)
#.   include "../../lang/python/application.mk"
#CONFIGURE_ARGS+=	--with-python
#CPPFLAGS+=		${BUILDLINK_CPPFLAGS.${PYPACKAGE}}
#LDFLAGS+=		${BUILDLINK_LDFLAGS.${PYPACKAGE}}
#.else
CONFIGURE_ARGS+=	--without-python
#.endif

.if defined(USE_VORBIS)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-vorbis=${BUILDINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.include "../../mk/bsd.pkg.mk"
