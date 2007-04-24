# $NetBSD: Makefile,v 1.10 2007/04/24 14:58:40 tnn2 Exp $
#

DISTNAME=		sawfish-${SF_VERS}
PKGNAME=		sawfish-gtk2-${SF_VERS}
SF_VERS=		1.3
CATEGORIES=		x11 gnome wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sawmill/}

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://sawmill.sourceforge.net/
COMMENT=		Extensible window manager that is fully configurable in Lisp

DEPENDS+=		rep-gtk2>=0.18:../../wip/rep-gtk2

CONFLICTS+=		sawfish-[0-9]*
CONFLICTS+=		sawfish-replibs-[0-9]*

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-audiofile --without-esd

USE_TOOLS+=		gmake makeinfo msgfmt
USE_PKGLOCALEDIR=	yes

INFO_FILES=		YES
PLIST_SUBST+=		SF_VERS=${SF_VERS:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
