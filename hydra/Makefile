# $NetBSD: Makefile,v 1.12 2005/02/07 09:42:21 adrian_p Exp $
#

DISTNAME=	${PKGNAME}-src
PKGNAME=	hydra-4.6
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.thc.org/
COMMENT=	Login password cracker

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
BUILD_TARGET=	all ssl

SUBST_CLASSES=		build
SUBST_STAGE.build=	post-patch
SUBST_FILES.build=	Makefile.am configure hydra-gtk/src/main.c
SUBST_SED.build=	-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|uname|${UNAME}|g" \
			-e "s|\./hydra|${PREFIX}/bin/hydra|g"
SUBST_MESSAGE.build=	"Patching build files."

USE_OLD_DES_API=	YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
CONFIGURE_ARGS+=	--prefix=${PREFIX}

PKG_OPTIONS_VAR=	PKG_OPTIONS.hydra
PKG_SUPPORTED_OPTIONS=	gtkfe

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkfe)

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/hydra-gtk && \
	${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC}/hydra-gtk && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin

PLIST_SRC+=	${PKGDIR}/PLIST.xhydra
.endif

pre-build:
	 @${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
