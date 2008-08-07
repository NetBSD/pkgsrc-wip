# $NetBSD: Makefile,v 1.10 2008/08/07 19:03:31 htepper Exp $

DISTNAME=		opensc-0.11.5
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/opensc/

MAINTAINER=		hasso@estpak.ee
HOMEPAGE=		http://www.opensc-project.org/openct/
COMMENT=		Smart Card drivers and middleware

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=		gmake pkg-config
USE_BUILTIN.openssl=	NO

.include "options.mk"

USE_OLD_DES_API=	YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-sensitive-logging

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}


.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
