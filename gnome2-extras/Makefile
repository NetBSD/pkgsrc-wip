# $NetBSD: Makefile,v 1.6 2003/07/13 17:52:14 thomasklausner Exp $

DISTNAME=	gnome2-extras-2.2.3
CATEGORIES=	meta-pkgs x11 gnome2
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	meta-package with extras for GNOME2

DEPENDS+=	gnome>=2.2.3:../../meta-pkgs/gnome2
DEPENDS+=	gnome2-pkgview>=1.0.0:../../wip/gnome2-pkgview
#DEPENDS+=	gnome2-themes-extra>=0.1:../../wip/gnome2-themes-extra
DEPENDS+=	regexxer>=0.4:../../wip/regexxer
DEPENDS+=	stickynotes-applet>=1.2.0:../../wip/stickynotes-applet
DEPENDS+=	zenity>=1.2:../../wip/zenity
DEPENDS+=	gtranslator>=0.99:../../wip/gtranslator
DEPENDS+=	tsclient>=0.104:../../wip/tsclient
DEPENDS+=	gmencoder>=0.0.7:../../wip/gmencoder
DEPENDS+=	gimp-current>=1.3.5:../../wip/gimp-current
DEPENDS+=	xchat>=2.0.1:../../chat/xchat2
DEPENDS+=	gaim>=0.60:../../chat/gaim

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
