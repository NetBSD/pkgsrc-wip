# $NetBSD: Makefile,v 1.1 2012/08/23 20:08:20 fhajny Exp $
#

MODNAME=	ffmpeg
PECL_VERSION=	0.6.0
PECL_DISTNAME=	ffmpeg-php-${PECL_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg-php/}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg-php.sourceforge.net/
COMMENT=	Access and retrieve information from movies and audio files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-ffmpeg=${BUILDLINK_PREFIX.ffmpeg}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
