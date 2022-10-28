# $NetBSD$

DISTNAME=	yash-2.53
CATEGORIES=	shells
MASTER_SITES=	https://free.nchc.org.tw/osdn/yash/77664/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://yash.osdn.jp/index.html.en
COMMENT=	POSIX-compliant command line shell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-history
CONFIGURE_ARGS+=	--enable-lineedit

USE_TOOLS+=		msgfmt msgmerge
USE_TOOLS+=		intltool xgettext

PKG_SHELL=	bin/yash

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
