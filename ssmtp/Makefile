# $NetBSD: Makefile,v 1.1.1.1 2003/06/06 09:20:54 takasan-tt Exp $
# FreeBSD Id: ports/mail/ssmtp/Makefile,v 1.10 2003/04/14 08:41:04 leeym Exp

DISTNAME=	ssmtp_2.60.3
PKGNAME=	ssmtp-2.60.3
WRKSRC=		${WRKDIR}/${PKGBASE}-${PKGVERSION:C/([0-9]+.[0-9]+)(.[0-9]+)$/\1/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/ssmtp/}

MAINTAINER=	pkg@pop.707.to
HOMEPAGE=	http://packages.debian.org/testing/mail/ssmtp.html
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES

CONFIGURE_ARGS+=	--enable-ssl --enable-inet6

PKG_SYSCONFSUBDIR=	${PKGBASE}

CONF_FILES=	${PREFIX}/share/examples/ssmtp/ssmtp.conf
CONF_FILES+=	${PKG_SYSCONFDIR}/ssmtp.conf
CONF_FILES+=	${PREFIX}/share/examples/ssmtp/revaliases
CONF_FILES+=	${PKG_SYSCONFDIR}/revaliases

post-configure:
	@for f in ${WRKSRC}/ssmtp.c ${WRKSRC}/ssmtp.conf ; do		\
		${MV} $${f} $${f}.orig ;				\
		${SED} "s,/etc/ssl/certs/ssmtp.pem,${PKG_SYSCONFDIR}/ssmtp.pem,g" \
			< $${f}.orig > $${f} ;				\
	done
	@${MV} ${WRKSRC}/ssmtp.8 ${WRKSRC}/ssmtp.8.orig
	@${SED} "s, /etc, ${PREFIX}/etc,g" < ${WRKSRC}/ssmtp.8.orig \
		> ${WRKSRC}/ssmtp.8

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ssmtp
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${PREFIX}/share/examples/ssmtp
	${INSTALL_DATA} ${WRKSRC}/revaliases ${PREFIX}/share/examples/ssmtp

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
