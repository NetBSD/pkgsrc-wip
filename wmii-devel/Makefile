# $NetBSD: Makefile,v 1.9 2008/03/08 19:42:27 tnn2 Exp $

DISTNAME=		wmii+ixp-20080120
PKGNAME=		wmii-20080120
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/snaps/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Window manager improved 2

DEPENDS+=		dmenu-[0-9]*:../../x11/dmenu

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/wmii+ixp-20080121

BUILD_DEFS+=		PKG_SYSCONFBASE
MAKE_ENV+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}

# see ${WRKSRC}/mk/wmii.mk
CONFVERSION=		3.5
PLIST_SUBST+=		CONFVERSION=${CONFVERSION}

PKG_SYSCONFSUBDIR=	wmii-${CONFVERSION}
EGDIR=			${PREFIX}/share/examples/${PKG_SYSCONFSUBDIR}
EGFILES=		rc.wmii welcome wmiirc
CONF_FILES_MODE=	0755

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# It's broken on NetBSD 4.99.31
#
MAKE_JOBS_SAFE=no

# bundles it's own libixp, which is needed until a new stable release is out.
#.include "../../devel/libixp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
