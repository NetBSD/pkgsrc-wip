# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:24 rillig Exp $
#

DISTNAME=		sawfish-${SF_VERS}
PKGNAME=		sawfish-gtk2-${SF_VERS}
SF_VERS=		1.3
CATEGORIES=		x11 gnome wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sawmill/}

MAINTAINER=		tnn@netilium.org
HOMEPAGE=		http://sawmill.sourceforge.net/
COMMENT=		Extensible window manager that is fully configurable in Lisp

DEPENDS+=		rep-gtk2>=0.18:../../wip/rep-gtk2

CONFLICTS+=		sawfish-*
CONFLICTS+=		sawfish-replibs-*

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
BUILD_USES_MSGFMT=	YES
GNU_CONFIGURE=		# defined
USE_X11=		# defined
CONFIGURE_ARGS+=	--without-audiofile --without-esd

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	# defined
USE_MAKEINFO=		YES

INFO_FILES=		sawfish.info
PLIST_SUBST+=		SF_VERS=${SF_VERS}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
