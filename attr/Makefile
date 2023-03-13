# $NetBSD: Makefile,v 1.7 2022/11/12 09:10:24 nikita Exp $

ATTR_VERS=	2.5.1
DISTNAME=	attr-${ATTR_VERS}
CATEGORIES=	sysutils
MASTER_SITES=	https://download.savannah.gnu.org/releases/attr/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/attr
COMMENT=	Commands for Manipulating Filesystem Extended Attributes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_LIBTOOL=		yes
#INSTALL_SH_OVERRIDE=	no

LDFLAGS.Darwin+=	-lintl
#LDFLAGS.NetBSD+=	-lintl

SUBST_CLASSES.Darwin+=	rmldarg
SUBST_CLASSES.SunOS+=	rmldarg
SUBST_STAGE.rmldarg=	pre-configure
SUBST_FILES.rmldarg=	libattr/Makefile
SUBST_SED.rmldarg=	-e '/version-script/d'

pre-install:
	cd ${WRKSRC}/libattr && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
                -f ${MAKE_FILE} install-lib install-dev
	cd ${WRKSRC}/include && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
                -f ${MAKE_FILE} install-dev

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
