# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	wyebadblock-0.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/jun7/wyebadblock

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jun7/wyebadblock
COMMENT=	adblock extension for wyeb, also webkit2gtk browsers
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	wyebadblock
GIT_REPO.wyebadblock=	https://github.com/jun7/wyebadblock
WRKSRC=			${WRKDIR}/wyebadblock

USE_TOOLS+=	gmake pkg-config

MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin lib/wyebrowser

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
