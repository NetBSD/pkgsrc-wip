# $NetBSD$

DISTNAME=	c3270-3.3.15ga9-src
PKGNAME=	c3270-3.3.15ga9
CATEGORIES=	net
MASTER_SITES=	http://x3270.bgp.nu/download/03.03.15/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulator ncurses
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/c3270-3.3
CONFLICTS=		x3270-[0-9]*
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	enable-c3270
USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	c3270

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
