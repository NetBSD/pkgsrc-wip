# $NetBSD: Makefile,v 1.3 2004/05/11 04:31:47 blef Exp $

DISTNAME=		vm-pop3d-1.1.6
PKGNAME=		vm-pop3d-1.1.7e
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/pop/}

PATCH_SITES=		http://www.reedmedia.net/software/virtualmail-pop3d/
PATCHFILES=		vm-pop3d-1.1.7e.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.reedmedia.net/software/virtualmail-pop3d/
COMMENT=		POP3 server with support for virtual mail accounts

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_PAM)
.include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	 --enable-pam
.else
CONFIGURE_ARGS+=	 --disable-pam
.endif

.include "../../mk/bsd.pkg.mk"
