# $NetBSD: Makefile,v 1.5 2015/07/11 09:56:34 thomasklausner Exp $

DISTNAME=	emerald-0.8.8
CATEGORIES=	wm
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/emerald/emerald-0.8.8.tar.bz2/6c6fbef2009461392ba927586df6635e/
#http://releases.compiz.org/0.8.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.compiz.org/Decorators/Emerald
COMMENT=	Emerald window decorator for compiz
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gtk-update-icon-cache msgfmt msgmerge intltool perl
USE_TOOLS+=	pkg-config update-desktop-database update-mime-database xgettext

PKGCONFIG_OVERRIDE+=	libengine/emeraldengine.pc.in

.include "options.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
.include "../../mk/bsd.pkg.mk"
