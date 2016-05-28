# $NetBSD: Makefile,v 1.12 2012/10/23 10:23:07 thomasklausner Exp $

DISTNAME=		wmii+ixp-snap20090703
PKGNAME=		wmii-20090703
CATEGORIES=		wm
MASTER_SITES=		http://code.suckless.org/dl/wmii/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Window manager improved 2

DEPENDS+=		dmenu-[0-9]*:../../x11/dmenu


USE_TOOLS+=		pkg-config
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}

BUILD_DEFS+=		PKG_SYSCONFBASE
MAKE_ENV+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}

# see ${WRKSRC}/mk/wmii.mk; uses "hg" to find out the version
# "hg" if it fails
CONFVERSION=		hg
PLIST_SUBST+=		CONFVERSION=${CONFVERSION}

PKG_SYSCONFSUBDIR=	wmii-${CONFVERSION}
EGDIR=			${PREFIX}/share/examples/${PKG_SYSCONFSUBDIR}
EGFILES=		rc.wmii welcome wmiirc
CONF_FILES_MODE=	0755

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# bundles it's own libixp, which is needed until a new stable release is out.
#.include "../../devel/libixp/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
