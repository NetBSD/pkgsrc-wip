# $NetBSD: Makefile,v 1.1.1.1 2004/03/20 20:12:11 xtraeme Exp $
#

DISTNAME=	galeon-1.3.13a
PKGNAME=	${DISTNAME:S/galeon/galeon-devel/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME2 Web browser based on gecko

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

WRKSRC=			${WRKDIR}/galeon-1.3.13
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

BUILDLINK_RPATHDIRS.mozilla-gtk2+=  lib/mozilla-gtk2

GCONF2_SCHEMAS+=	galeon.schemas

CONFIGURE_ARGS+=	--with-mozilla-snapshot=1.6

EGDIR=			${PREFIX}/share/examples/galeon2
CONF_FILES=		${EGDIR}/galeon.soundlist \
			${PKG_SYSCONFDIR}/galeon.soundlist

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
