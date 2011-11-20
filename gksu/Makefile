# $NetBSD: Makefile,v 1.5 2011/11/20 15:55:28 noud4 Exp $
#

DISTNAME=		gksu-1.3.6
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/old_stuff/gksu/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/gksu/
COMMENT=		Authorization dialog library

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Linux"	# others?
DEPENDS+=		gnome-terminal>=2.32.1:../../x11/gnome-terminal
.endif

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
USE_TOOLS+=		perl:build
USE_TOOLS+=		bash:run
GNU_CONFIGURE=		yes

USE_X11=YES

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=	gksu.schemas

SUBST_CLASSES+=		sudo
SUBST_FILES.sudo=	po/es.po po/pl.po po/pt_BR.po
SUBST_SED.sudo=		-e 's,/usr/bin/sudo,${PREFIX}/bin/sudo,g'
SUBST_STAGE.sudo=	post-configure

SUBST_CLASSES+=		su
SUBST_FILES.su=		po/es.po po/nb.po po/pl.po po/pt_BR.po po/ro.po po/ru.po
SUBST_SED.su=		-e 's,/bin/su:,${SU}:,g'
SUBST_STAGE.su=		post-configure

SUBST_CLASSES+=		gksu
SUBST_FILES.gksu=	po/ca.po po/cs.po po/da.po po/de.po po/es.po po/fr.po po/hu.po po/pl.po po/pl.po \
			po/pt.po po/pt_BR.po po/ro.po po/ru.po po/nb.po po/nl.po po/sk.po po/xh.po
SUBST_SED.gksu=		-e 's,/bin/gksu,${PREFIX}/bin/gksu,g'
SUBST_STAGE.gksu=	post-configure

SUBST_CLASSES+=		term
SUBST_FILES.term=	gksu.desktop
.if ${OPSYS} != "Linux"
SUBST_SED.term=		-e 's,/usr/bin/x-terminal-emulator,${PREFIX}/bin/gnome-terminal,g'
.endif
SUBST_STAGE.term=	post-configure

REPLACE_BASH+=		gksu-migrate-conf.sh

.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libgksu/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../wip/libgksuui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
