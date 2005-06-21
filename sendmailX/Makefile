# $NetBSD: Makefile,v 1.1.1.1 2005/06/21 21:37:58 adrian_p Exp $

DISTNAME=	smX-${VERSION}
PKGNAME=	sendmailX-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.sendmail.org/
COMMENT=	Something to do with mail

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	postfix-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES
PTHREAD_OPTS+=	require
VERSION=	0.0.Alpha3.0

PKG_GROUPS=     smxs smxq smxc smxm smx
PKG_USERS=      smxs:smxs::Sendmail\\ X\\ SMTPS
PKG_USERS+=	smxq:smxq::Sendmail\\ X\\ QMGR
PKG_USERS+=	smxc:smxc::Sendmail\\ X\\ SMTPC
PKG_USERS+=	smxm:smxm::Sendmail\\ X\\ misc

CONFIGURE_ARGS+=	--disable-TLS
CONFIGURE_ARGS+=	--disable-SASL

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
