# $NetBSD$

DISTNAME=	isa-l-2.31.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

OWNER=		pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/intel/isa-l
COMMENT=	Intel(R) Intelligent Storage Acceleration Libray
LICENSE=	modified-bsd

SUBST_CLASSES+=	lt
SUBST_STAGE.lt=	post-configure
SUBST_SED.lt=	-e 's|--mode=compile|--tag=CC --mode=compile|g'
SUBST_FILES.lt=	Makefile

DEPENDS=	nasm>0:../../devel/nasm

USE_TOOLS+=	autoconf automake autoreconf gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	(cd ${WRKSRC} && autoreconf --install --symlink -f -Wno-obsolete)

.include "../../mk/bsd.pkg.mk"
