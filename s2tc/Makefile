# $NetBSD$

GITHUB_PROJECT=	s2tc
DISTNAME=	v1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=divVerent/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/divVerent/s2tc/
COMMENT=	S2TC - a subset of a well known texture compression scheme
LICENSE=	mit

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/s2tc-1.0
USE_TOOLS+=	autoconf automake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

DL_AUTO_VARS=	yes

PKGCONFIG_OVERRIDE+=	txc_dxtn.pc.in

INSTALL_TEMPLATES=	${FILESDIR}/INSTALL
DEINSTALL_TEMPLATES=	${FILESDIR}/DEINSTALL

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
