# $NetBSD: Makefile,v 1.6 2004/01/14 22:45:31 thomasklausner Exp $
#

DISTNAME=	ices-0.2.3
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	MP3/Vorbis encoder for icecast servers

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-lame=${BUILDLINK_PREFIX.lame} \
			--with-perl=${BUILDLINK_PREFIX.perl} \
			--with-xml=${BUILDLINK_PREFIX.libxml2}/bin \
			--with-docdir=${LOCALBASE}/share/doc/ices \
			--with-libshout=${BUILDLINK_PREFIX.libshout}

.include "../../audio/libshout/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"

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
.   include "../../audio/libvorbis/buildlink2.mk"
CONFIGURE_ARGS+=	--with-vorbis=${BUILDINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.include "../../mk/bsd.pkg.mk"
