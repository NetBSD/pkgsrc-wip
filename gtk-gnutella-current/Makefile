# $NetBSD: Makefile,v 1.4 2005/01/21 07:17:21 larnor Exp $

DISTNAME=		gtk-gnutella-current-${GTK_GNUTELLA_VER}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		# not defined

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTK-based gnutella client, CVS snapshot

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
BUILD_DEPENDS+=		../../devel/gettext
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d -e -r -s -D prefix="${PREFIX}" -D cc="${CC}" \
			-D privlib="${PREFIX}/share/gtk-gnutella" \
			-D sysman="${PREFIX}/man" -D cflags="${CFLAGS}" \
			-D locale="${PREFIX}/${PKGLOCALEDIR}/locale" \
			-D optimize="${COPTS}" -D gtkversion=2 -D yacc="yacc"

CONFLICTS=		gtk-gnutella-*

CVS_REPOSITORY=		${CVS_REPOSITORY_SOURCEFORGE}/gtk-gnutella
CVS_MODULE=		gtk-gnutella-current

# Dynamic plist is a pkgviews feature.
#PLIST_TYPE=		dynamic
NO_CHECKSUM=		# defined

# Not pkgviews-enabled yet because of problems generating the date-like version
# number.
#PKG_INSTALLATION_TYPE=	pkgviews

.include "../../wip/gtk-gnutella-current/Makefile.version"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
