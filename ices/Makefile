# $NetBSD: Makefile,v 1.1.1.1 2003/04/11 20:03:40 icmp Exp $
#

DISTNAME=	ices-0.2.3
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	MP3/Vorbis encoder for icecast servers

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-lame=${BUILDLINK_PREFIX.lame} \
			--with-perl=${BUILDLINK_PREFIX.perl} \
			--with-xml=${BUILDLINK_PREFIX.libxml2}/bin

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
