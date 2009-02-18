# $NetBSD: Makefile,v 1.2 2009/02/18 11:00:44 htepper Exp $

PKGNAME=		opensc-signer-${OPENSC_PKG_VERSION}
COMMENT=		Opensc signer plugin for Mozilla apps

.include "../../wip/opensc/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../wip/opensc/distinfo
PATCHDIR=		${.CURDIR}/../../wip/opensc/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-nsplugin
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/mozilla/plugins
CONFIGURE_ARGS+=	--with-pinentry=${PREFIX}/bin/pinentry

do-install:
	cd ${WRKSRC}/src/signer && ${SETENV} ${MAKE_ENV} ${MAKE} \
		prefix=${DESTDIR}${PREFIX} \
		plugindir=${DESTDIR}${PREFIX}/lib/mozilla/plugins install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
