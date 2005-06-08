# $NetBSD: Makefile,v 1.3 2005/06/08 15:47:03 dillo Exp $
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
USE_X11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

pre-configure:
		cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
