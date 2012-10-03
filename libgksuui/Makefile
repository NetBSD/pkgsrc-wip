# $NetBSD: Makefile,v 1.5 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=		libgksuui1.0-1.0.7
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/old_stuff/libgksuui1.0/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://people.debian.org/~kov/gksu/
COMMENT=		UI Support library for Gksu

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libgksuui/libgksuui1.0.pc.in

SUBST_CLASSES+=	nodocs
SUBST_FILES.nodocs=	Makefile
SUBST_SED.nodocs  =  -e 's,docs,,g'
SUBST_STAGE.nodocs = post-configure

SUBST_CLASSES+=		icon
SUBST_FILES.icon=	libgksuui/test-gksuui.c
SUBST_SED.icon=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_STAGE.icon=	post-configure

SUBST_CLASSES+=		sudo
SUBST_FILES.sudo=	po/es.po po/pl.po po/pt_BR.po
SUBST_SED.sudo=		-e 's,/usr/bin/sudo,${PREFIX}/bin/sudo,g'
SUBST_STAGE.sudo=	post-configure

SUBST_CLASSES+=		su
SUBST_FILES.su=		po/es.po po/nb.po po/pl.po po/pt_BR.po po/ru.po
SUBST_SED.su=		-e 's,/bin/su:,${SU}:,g'
SUBST_STAGE.su=		post-configure

SUBST_CLASSES+=		gksu
SUBST_FILES.gksu=	po/es.po po/nb.po po/pl.po po/pt_BR.po po/ru.po
SUBST_SED.gksu=		-e 's,/bin/gksu,${PREFIX}/bin/gksu,g'
SUBST_STAGE.gksu=	post-configure

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
