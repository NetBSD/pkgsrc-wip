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

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
USE_GNU_CONFIGURE_HOST=	no

XSB_VERSION_STR=	xsb-5.0.0
# The source uses P_tmpdir, u_long which are under _NETBSD_SOURCE flag in respective headers
CONFIGURE_ARGS+=	--with-cflags=-D_NETBSD_SOURCE
CONFIGURE_ARGS+=	--with-site-prefix=${PREFIX}/${XSB_VERSION_STR}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/${XSB_VERSION_STR}

REPLACE_BASH+=	${WRKDIR}/XSB/packages/xasp/makelinks.sh
INSTALLATION_DIRS+=	bin
XSB_BIN=	${DESTDIR}${PREFIX}/${XSB_VERSION_STR}/bin/xsb

do-build:
	cd ${WRKSRC} && ./makexsb fast packages

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} ./makexsb install && \
	${INSTALL} ${XSB_BIN} ${DESTDIR}${PREFIX}/bin

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
