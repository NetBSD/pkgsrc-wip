# $NetBSD: Makefile,v 1.6 2005/01/02 23:23:34 mattd Exp $
#

DISTNAME=	matchbox-panel-0.8.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/projects/matchbox/sources/matchbox-panel/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Panel for Matchbox

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
AUTOCONF_REQD=		2.53

CONFIGURE_ARGS+=	--enable-small-icons
CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-nls

BUILD_DEPENDS+=		gettext>=0.11.5:../../devel/gettext

CONFIGURE_ENV+=		XGETTEXT=${LOCALBASE}/bin/xgettext
CONFIGURE_ENV+=		GMSGFMT=${LOCALBASE}/bin/msgfmt
CONFIGURE_ENV+=		MSGFMT=${LOCALBASE}/bin/msgfmt
CONFIGURE_ENV+=		MSGMERGE=${LOCALBASE}/bin/msgmerge

# Regenerate files after patching. This will disappear in next version,
# patches have been sent upstream.
#
pre-configure:
	cd ${WRKSRC};							\
	${ACLOCAL};							\
	${AUTOHEADER};							\
	${AUTOMAKE} -a --foreign -i;					\
	${AUTOCONF}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
