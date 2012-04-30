# $NetBSD: Makefile,v 1.2 2012/04/30 15:11:56 ftigeot Exp $

DISTNAME=	opensmtpd-201204120900
CATEGORIES=	mail net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/opensmtpd

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	automake aclocal autoheader autoconf

GNU_CONFIGURE=	yes

SMTPD_CONF=	${PKG_SYSCONFDIR}/smtpd.conf
CONF_FILES=	${PREFIX}/etc/mail/smtpd.conf ${PKG_SYSCONFDIR}/mail/smtpd.conf

pre-configure:
	set -e; cd ${WRKSRC}; \
	PATH=/bin:/usr/bin:/usr/pkg/bin ./bootstrap

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
