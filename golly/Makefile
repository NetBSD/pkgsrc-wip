# $NetBSD$

PKGVERSION=	3.0
PKGNAME=	golly-${PKGVERSION}
DISTNAME=	${PKGNAME}-src
#PKGREVISION=	0
CATEGORIES=	x11
# MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golly/} results in http://downloads.sourceforge.net/sourceforge/golly/golly-3.0.tar.gz
# we want https://sourceforge.net/projects/golly/files/golly/golly-3.0/golly-3.0-src.tar.gz
MASTER_SITES=	https://sourceforge.net/projects/golly/files/golly/${PKGNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golly.sourceforge.net/
COMMENT=	Fast Game-Of-Life (and similar automata) program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	make
CONFIGURE_DIRS=	gui-wx/configure
#CONFIGURE_SCRIPT=./configure
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+="CFLAGS=--std=c99"	# for long long in luaconf.h -> limits.h

.include "../../mk/bsd.pkg.debug.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#.include "../../lang/lua/buildlink3.mk" # uses its own built-in version 5.2
.include "../../lang/python27/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
