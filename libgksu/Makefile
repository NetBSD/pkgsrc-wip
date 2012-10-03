# $NetBSD: Makefile,v 1.4 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=		libgksu1.2-1.3.7
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/old_stuff/libgksu1.2/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/gksu/
COMMENT=		Support library for gksu

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=		xauth>=1.0.4:../../x11/xauth
.endif
DEPENDS+=		sudo>=1.7.8:../../security/sudo
.if ${OPSYS} != "Linux"	# others?
DEPENDS+=		gnome-terminal>=2.32.1:../../x11/gnome-terminal
.endif

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

SUBST_CLASSES+=   nodocs
SUBST_FILES.nodocs=  Makefile
SUBST_SED.nodocs  =  -e 's,docs,,g'
SUBST_STAGE.nodocs = post-configure

SUBST_CLASSES+=		sudo
SUBST_FILES.sudo=	libgksu/gksu-context.c po/es.po po/pl.po po/pt_BR.po
SUBST_SED.sudo=		-e 's,/usr/bin/sudo,${PREFIX}/bin/sudo,g'
SUBST_STAGE.sudo=	post-configure

SUBST_CLASSES+=		su
SUBST_FILES.su=		po/ru.po po/libgksu1.2.pot po/ca.po po/cs.po po/da.po po/de.po po/es.po \
			po/eu.po po/hu.po po/pl.po po/pt_BR.po po/ro.po po/sk.po po/nb.po po/nl.po
SUBST_SED.su=		-e 's, /bin/su:, ${SU}:,g'
SUBST_STAGE.su=		post-configure

SUBST_CLASSES+=		SU
SUBST_FILES.SU=		libgksu/gksu-context.c po/eu.po po/nl.po po/hu.po
SUBST_SED.SU=		-e 's,@SU@,${SU},g'
SUBST_STAGE.SU=		post-configure

SUBST_CLASSES+=		gksu
SUBST_FILES.gksu=	po/de.po po/es.po po/nb.po po/pl.po po/pt_BR.po po/ru.po
SUBST_SED.gksu=		-e 's,/bin/gksu,${PREFIX}/bin/gksu,g'
SUBST_STAGE.gksu=	post-configure

SUBST_CLASSES+=		xauth
SUBST_FILES.xauth=	libgksu/gksu-run-helper.c libgksu/gksu-context.c
.if ${X11_TYPE} == "modular"
SUBST_SED.xauth=	-e 's,/usr/X11R6/bin/xauth,${PREFIX}/bin/xauth,g'
.elif ${OPSYS} != "Linux"
SUBST_SED.xauth=	-e 's,/usr/X11R6/bin/xauth,/usr/X11R7/bin/xauth,g'
.endif
SUBST_STAGE.xauth=	post-configure

SUBST_CLASSES+=		xterm
SUBST_FILES.xterm=	libgksu/test-gksu.c
.if ${OPSYS} != "Linux"
SUBST_SED.xterm=	-e 's,/usr/bin/X11/xterm,${PREFIX}/bin/gnome-terminal,g'
.endif
SUBST_STAGE.xterm=	post-configure

PKGCONFIG_OVERRIDE+=	libgksu/libgksu1.2.pc.in

post-patch:
	${RM} ${WRKSRC}/po/*.orig

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

