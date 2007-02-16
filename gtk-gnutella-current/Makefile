# $NetBSD: Makefile,v 1.17 2007/02/16 00:07:08 larnor Exp $

DISTNAME=		gtk-gnutella-${GTK_GNUTELLA_VER}
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		# not defined

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTK-based gnutella client, SVN snapshot

# Debug
#CFLAGS+=		-g

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d -e -r -s -D prefix=${PREFIX:Q} -D cc=${CC:Q} \
			-D privlib="${PREFIX}/share/gtk-gnutella" \
			-D sysman="${PREFIX}/${PKGMANDIR}" \
			-D cflags=${CFLAGS:M*:Q} \
			-D locale="${PREFIX}/${PKGLOCALEDIR}/locale" \
			-D optimize=${COPTS:Q} -D gtkversion=2 -D yacc="yacc" \
			-D official=false

CONFLICTS=		gtk-gnutella-*

SVN_REPOSITORIES=	gtk-gnutella
SVN_CERTS=		files/dc5a395eac239ee84380e60694cec8f1
SVN_ROOT.gtk-gnutella=	${SVN_ROOT_SOURCEFORGE}/gtk-gnutella/trunk/gtk-gnutella
SVN_MODULE.gtk-gnutella=gtk-gnutella

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
