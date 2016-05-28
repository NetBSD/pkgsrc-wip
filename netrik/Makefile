# $NetBSD: Makefile,v 1.5 2012/10/03 18:15:32 asau Exp $

DISTNAME=		netrik-1.15.4
PKGREVISION=		1
CATEGORIES=		www net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netrik/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://netrik.sourceforge.net/
COMMENT=		Will be a really fancy text mode WWW browser


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_BUILTIN.ncurses=	no
DEPENDS+=		wget>=1.10.0:../../net/wget

# Ensure that it uses wget from pkgsrc
CONFIGURE_ARGS+=	--with-wget-call="${PREFIX}/bin/wget -nv -O- '%s'"

PKG_OPTIONS_VAR=	PKG_OPTIONS.netrik
PKG_SUPPORTED_OPTIONS=	readline
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
