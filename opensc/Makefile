# $NetBSD: Makefile,v 1.13 2009/02/18 10:16:04 htepper Exp $

PKGREVISION=		2
COMMENT=		Smart Card drivers and middleware

.include "../../wip/opensc/Makefile.common"

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-nsplugin

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
