# $NetBSD: Makefile,v 1.1.1.1 2012/04/11 07:25:50 ftigeot Exp $

DISTNAME=	opensmtpd-201203192144
CATEGORIES=	mail net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/opensmtpd-snapshot

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	automake aclocal autoheader autoconf

GNU_CONFIGURE=	yes

CONF_FILES=	${PKG_SYSCONFDIR}/mail/smtpd.conf

pre-configure:
	touch ${WRKSRC}/ltmain.sh
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf
#	PATH=/bin:/usr/bin:/usr/pkg/bin ./bootstrap

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
