# $NetBSD: Makefile,v 1.9 2014/10/09 14:06:27 thomasklausner Exp $
#

DISTNAME=	ftpd-tls-20031008
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/			\
		ftp://ftp.runestig.com/pub/ftpd-tls/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	ftp://ftp.zeist.de/pub/distfiles/
COMMENT=	Ftp server supporting FTP AUTH TLS

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	ftpdtls

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing hardcoded path.
SUBST_FILES.path=	ftpd.8.TLS pathnames.h tlsutil.c README.TLS
SUBST_SED.path=		-e "s|/etc|${PKG_SYSCONFBASE}|"			\
			-e "s|/ftpd|/${PKGBASE}|"

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
MESSAGE_SUBST+=		PKGBASE=${PKGBASE}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS}

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8

do-install:
		${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
		${INSTALL_PROGRAM} ${WRKSRC}/ftpd ${DESTDIR}${PREFIX}/libexec/ftpd-tls
		${INSTALL_MAN} ${WRKSRC}/ftpd.8.TLS \
					${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ftpd-tls.8
		${INSTALL_DATA} ${WRKSRC}/README.TLS ${DESTDIR}${DOCDIR}/README.TLS

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
