# $NetBSD: Makefile,v 1.24 2012/11/13 20:09:31 othyro Exp $

DISTNAME=		gtk-gnutella-${GTK_GNUTELLA_VER}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		# not defined

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTK-based gnutella client, GIT snapshot


# Debug
CFLAGS=		-g

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./build.sh
CONFIGURE_ARGS+=	--configure-only
CONFIGURE_ARGS+=	--prefix=${DESTDIR}/${PREFIX}
CONFIGURE_ARGS+=	--localedir="${PREFIX}/${PKGLOCALEDIR}/locale"
CONFIGURE_ARGS+=	--cc=${CC:Q}
CONFIGURE_ARGS+=	--cflags=${CFLAGS:Unone:Q}
CONFIGURE_ARGS+=	--yacc="yacc"

CONFLICTS=		gtk-gnutella-*

GIT_REPOSITORIES=	master
GIT_REPO.master=	http://github.com/gtk-gnutella/gtk-gnutella.git

WRKSRC=			${WRKDIR}/gtk-gnutella

NO_CHECKSUM=		yes

USE_BUILTIN.gettext=	no

distclean:
	@${DO_NADA}


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/gtk-gnutella-git/Makefile.version"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
