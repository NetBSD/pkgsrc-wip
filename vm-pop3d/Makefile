# $NetBSD: Makefile,v 1.6 2012/10/07 17:41:43 asau Exp $

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


GNU_CONFIGURE=		YES

PKG_OPTIONS_VAR=	PKG_OPTIONS.vm-pop3d
PKG_SUPPORTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	 --enable-pam
.else
CONFIGURE_ARGS+=	 --disable-pam
.endif

.include "../../mk/bsd.pkg.mk"
