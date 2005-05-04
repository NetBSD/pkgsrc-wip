# $NetBSD: Makefile,v 1.3 2005/05/04 00:43:51 jeremy-c-reed Exp $
#

DISTNAME=		gnome-alsamixer-0.9.6
CATEGORIES=		audio gnome
MASTER_SITES=		ftp://ftp.paw.co.za/pub/PAW/sources/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.paw.za.org/projects/gnome-alsamixer/
COMMENT=		Sound mixer for Advanced Linux Sound Architecture (ALSA)

GNU_CONFIGURE=		yes

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../wip/alsa-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
