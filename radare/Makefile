# $NetBSD: Makefile,v 1.5 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	radare-0.8.6
PKGREVISION=	1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://radare.nopcode.org/get/

MAINTAINER=	pancake@youterm.com
HOMEPAGE=	http://radare.nopcode.org/
COMMENT=	advanced commandline hexadecimal editor

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=	c perl

USE_TOOLS=	gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=	yes

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
