# $NetBSD: Makefile,v 1.15 2006/11/29 21:31:40 larnor Exp $

DISTNAME=		gtk-gnutella-${GTK_GNUTELLA_VER}
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		# not defined

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTK-based gnutella client, SVN snapshot

USE_TOOLS+=		gmake msgfmt
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
SVN_ROOT.gtk-gnutella=	${SVN_ROOT_SOURCEFORGE}/gtk-gnutella/trunk/gtk-gnutella
SVN_MODULE.gtk-gnutella=gtk-gnutella

WRKSRC=			${WRKDIR}/gtk-gnutella

NO_CHECKSUM=		yes

USE_BUILTIN.gettext=	no

SUBST_CLASSES+=		common_h
SUBST_STAGE.common_h=	pre-build
SUBST_FILES.common_h=	src/common.h
SUBST_SED.common_h=	-e "s|\#include <sys/sysctl\.h>|/\* \#include <sys/sysctl\.h> \*/|g"

distclean:
	@${DO_NADA}

.include "../../wip/gtk-gnutella-current/Makefile.version"

.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../wip/mk/svn-package.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
