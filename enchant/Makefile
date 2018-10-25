# $NetBSD: Makefile,v 1.38 2018/10/24 15:42:47 bsiegert Exp $
#

DISTNAME=		enchant-2.2.3
CATEGORIES=		textproc
MASTER_SITES=		https://github.com/AbiWord/enchant/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://abiword.github.io/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
