# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:26 kristerw Exp $
#

DISTNAME=		pwsafe-0.1.6
CATEGORIES=		security wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pwsafe/} \
			http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://nsd.dyndns.org/pwsafe/
COMMENT=		CLI based PasswordSafe compatible password manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf

PKG_OPTIONS_VAR=	PKG_OPTIONS.pwsafe
PKG_SUPPORTED_OPTIONS=	readline x11
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
.  if ${OPSYS} == "NetBSD"
# The NetBSD readline implementation isn't GNU compatible
USE_BUILTIN.readline=	no
.  endif
.  include "../../devel/readline/buildlink3.mk"
.  include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

pre-configure:
		cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
