# $NetBSD$

DISTNAME=	XSB-5.0
CATEGORIES=	lang
MASTER_SITES=	https://sourceforge.net/projects/xsb/files/xsb/5.0%20%28Green%20Tea%29/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xsb.sourceforge.net/
COMMENT=	Logic Programming and Deductive Database system
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/XSB/build

# There is "hard link not found" error for MSVC.sh with stock tar
EXTRACT_USING=	gtar

GNU_CONFIGURE=		yes
AUTOCONF_REQD=		2.7
GNU_CONFIGURE_STRICT=	no
USE_GNU_CONFIGURE_HOST=	no

# The source uses P_tmpdir, u_long which are under _NETBSD_SOURCE flag in respective headers
CONFIGURE_ARGS+=	--with-cflags=-D_NETBSD_SOURCE
CONFIGURE_ARGS+=	--with-site-prefix=${PREFIX}/xsb-5.0.0
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/xsb-5.0.0


do-build:
	cd ${WRKSRC} && ./makexsb fast

#do-install:
#	cd ${WRKSRC} && ./makexsb install


.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
