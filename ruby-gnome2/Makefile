# $NetBSD: Makefile,v 1.1.1.1 2006/01/07 17:46:57 roelants Exp $
#

PKGNAME=	ruby-gnome2-${VERSION}
COMMENT=	Set of Ruby language bindings for GNOME2
DISTFILES=	# empty
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	ruby-gnome2-atk>=${VERSION}:../../wip/ruby-gnome2-atk
DEPENDS+=	ruby-gnome2-gdkpixbuf>=${VERSION}:../../wip/ruby-gnome2-gdkpixbuf
DEPENDS+=	ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
DEPENDS+=	ruby-gnome2-gnome>=${VERSION}:../../wip/ruby-gnome2-gnome
DEPENDS+=	ruby-gnome2-gnomecanvas>=${VERSION}:../../wip/ruby-gnome2-gnomecanvas
DEPENDS+=	ruby-gnome2-gtk>=${VERSION}:../../wip/ruby-gnome2-gtk
DEPENDS+=	ruby-gnome2-libart>=${VERSION}:../../wip/ruby-gnome2-libart
DEPENDS+=	ruby-gnome2-panelapplet>=${VERSION}:../../wip/ruby-gnome2-panelapplet
DEPENDS+=	ruby-gnome2-pango>=${VERSION}:../../wip/ruby-gnome2-pango

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "${.CURDIR}/Makefile.common"
