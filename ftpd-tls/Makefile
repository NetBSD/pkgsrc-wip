# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 09:34:03 imilh Exp $
#

DISTNAME=	ftpd-tls-20031008
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/			\
		ftp://ftp.runestig.com/pub/ftpd-tls/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	ftp://ftp.zeist.de/pub/distfiles/
COMMENT=	Ftp server supporting FTP AUTH TLS

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

USE_PKGINSTALL=	yes
RCD_SCRIPTS=	ftpdtls

SUBST_CLASSES+=	path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing hardcoded path.
SUBST_FILES.path=	ftpd.8.TLS pathnames.h tlsutil.c README.TLS
SUBST_SED.path=		-e "s|/etc|${PKG_SYSCONFBASE}|"			\
			-e "s|/ftpd|/${PKGBASE}|"

EGDIR=			${PREFIX}/share/${PKGBASE}
MESSAGE_SUBST+=		PKGBASE=${PKGBASE}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS}

do-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
		${INSTALL_PROGRAM} ${WRKSRC}/ftpd ${PREFIX}/libexec/ftpd-tls
		${INSTALL_MAN} ${WRKSRC}/ftpd.8.TLS \
					${PREFIX}/man/man8/ftpd-tls.8
		${INSTALL_DATA} ${WRKSRC}/README.TLS ${EGDIR}

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
