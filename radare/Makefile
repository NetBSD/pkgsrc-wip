# $NetBSD: Makefile,v 1.4 2009/05/20 00:58:42 thomasklausner Exp $
#

DISTNAME=	radare-0.8.6
PKGREVISION=	1
CATEGORIES=	wip sysutils
MASTER_SITES=	http://radare.nopcode.org/get/

MAINTAINER=	pancake@youterm.com
HOMEPAGE=	http://radare.nopcode.org/
COMMENT=	advanced commandline hexadecimal editor

USE_LANGUAGES=	c perl

USE_TOOLS=	gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=	yes

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
