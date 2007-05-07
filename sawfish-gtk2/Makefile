# $NetBSD: Makefile,v 1.11 2007/05/07 18:58:33 tnn2 Exp $
#

DISTNAME=		sawfish-${SF_VERS}
PKGNAME=		sawfish-gtk2-${SF_VERS}
SF_VERS=		1.3
PKGREVISION=		1
CATEGORIES=		x11 wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sawmill/}

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://sawmill.sourceforge.net/
COMMENT=		Extensible window manager that is fully configurable in Lisp

DEPENDS+=		librep>=0.17nb3:../../lang/librep
DEPENDS+=		rep-gtk2>=0.18:../../wip/rep-gtk2

CONFLICTS+=		sawfish-[0-9]*
CONFLICTS+=		sawfish-replibs-[0-9]*

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}
MAKE_ENV+=		REP_ENV_PKGSRC=${REP_ENV_PKGSRC:Q}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-audiofile --without-esd

USE_TOOLS+=		gmake makeinfo msgfmt
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes

INFO_FILES=		YES
PLIST_SUBST+=		SF_VERS=${SF_VERS:Q}

SUBST_CLASSES+=		env
SUBST_STAGE.env=	pre-configure
SUBST_FILES.env=	lisp/sawfish/ui/main.jl.in po/sawfish-xgettext
SUBST_FILES.env+=	scripts/sawfish-*.jl* themer/themer.in
SUBST_SED.env=		-e 's,exec rep,env ${REP_ENV_PKGSRC} rep,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && empty(${OS_VERSION:M1.*})
REP_ENV_PKGSRC=		LD_PRELOAD=/usr/lib/libpthread.so
.else
REP_ENV_PKGSRC=
.endif

.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
