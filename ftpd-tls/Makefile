# $NetBSD: Makefile,v 1.7 2010/01/17 12:03:25 thomasklausner Exp $
#

DISTNAME=	ftpd-tls-20031008
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/			\
		ftp://ftp.runestig.com/pub/ftpd-tls/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	ftp://ftp.zeist.de/pub/distfiles/
COMMENT=	Ftp server supporting FTP AUTH TLS

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	ftpdtls

SUBST_CLASSES+=	path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing hardcoded path.
SUBST_FILES.path=	ftpd.8.TLS pathnames.h tlsutil.c README.TLS
SUBST_SED.path=		-e "s|/etc|${PKG_SYSCONFBASE}|"			\
			-e "s|/ftpd|/${PKGBASE}|"

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
MESSAGE_SUBST+=		PKGBASE=${PKGBASE}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS}

do-install:
		${INSTALL_DATA_DIR} ${DOCDIR}
		${INSTALL_PROGRAM} ${WRKSRC}/ftpd ${PREFIX}/libexec/ftpd-tls
		${INSTALL_MAN} ${WRKSRC}/ftpd.8.TLS \
					${PREFIX}/${PKGMANDIR}/man8/ftpd-tls.8
		${INSTALL_DATA} ${WRKSRC}/README.TLS ${DOCDIR}/README.TLS

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
