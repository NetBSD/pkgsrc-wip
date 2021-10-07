# $NetBSD$

GITHUB_PROJECT=	nyxt
GITHUB_TAG=	2.2.0
DISTNAME=	2.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=atlas-engineer/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/atlas-engineer/nyxt/
COMMENT=	Terminal browser
LICENSE=	original-bsd


.include "../../textproc/enchant2/buildlink3.mk"
.include "../../net/glib-networking/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/sbcl/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../wip/libfixposix/buildlink3.mk"
.include "../../x11/xclip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
