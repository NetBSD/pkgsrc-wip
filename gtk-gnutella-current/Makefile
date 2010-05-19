# $NetBSD: Makefile,v 1.21 2010/05/19 22:10:09 larnor Exp $

DISTNAME=		gtk-gnutella-${GTK_GNUTELLA_VER}
CATEGORIES=		net
MASTER_SITES=		# not defined

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTK-based gnutella client, SVN snapshot

# Debug
#CFLAGS+=		-g

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

SVN_REPOSITORIES+=	gtk-gnutella
SVN_MODULE.gtk-gnutella=gtk-gnutella
SVN_ROOT.gtk-gnutella=	https://gtk-gnutella.svn.sourceforge.net/svnroot/gtk-gnutella/trunk/gtk-gnutella
SVN_CERTS=		files/163e5491b8f4ccb8a4ab62c3ea0219c9

WRKSRC=			${WRKDIR}/gtk-gnutella

NO_CHECKSUM=		yes

USE_BUILTIN.gettext=	no

distclean:
	@${DO_NADA}

.include "../../wip/gtk-gnutella-current/Makefile.version"

.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
