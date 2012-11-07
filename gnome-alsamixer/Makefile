# $NetBSD: Makefile,v 1.9 2012/11/07 03:07:09 othyro Exp $
#

DISTNAME=		gnome-alsamixer-0.9.6
PKGREVISION=		4
CATEGORIES=		audio gnome
MASTER_SITES=		ftp://ftp.paw.co.za/pub/PAW/sources/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.paw.za.org/projects/gnome-alsamixer/
COMMENT=		Sound mixer for Advanced Linux Sound Architecture (ALSA)

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
