# $NetBSD: Makefile,v 1.3 2005/07/18 19:13:20 adrian_p Exp $

DISTNAME=	smX-${VERSION}
PKGNAME=	sendmailX-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.sendmail.org/
COMMENT=	Something to do with mail

CONFLICTS+=	postfix-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES
PTHREAD_OPTS+=	require
VERSION=	0.0.Alpha8.0

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

PKG_GROUPS=     smxs smxq smxc smxm smx
PKG_USERS=      smxs:smxs::Sendmail\\ X\\ SMTPS
PKG_USERS+=	smxq:smxq::Sendmail\\ X\\ QMGR
PKG_USERS+=	smxc:smxc::Sendmail\\ X\\ SMTPC
PKG_USERS+=	smxm:smxm::Sendmail\\ X\\ misc

CONFIGURE_ARGS+=	--disable-TLS
CONFIGURE_ARGS+=	--disable-SASL

# Note: Do not use Berkeley DB 4.3.27/28 in 64 bit mode on Solaris 5.8/9 as 
# it crashes at least in those configurations. This bug is fixed in the 
# version that is distributed with sendmail X. 
#
# This is unconfirmed on pkgsrc so we roll with the pkgsrc version of db4.
#
CONFIGURE_ARGS+=	--disable-included-bdb 

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
